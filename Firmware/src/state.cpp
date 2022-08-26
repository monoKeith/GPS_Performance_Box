#include "state.h"

namespace state
{

    /* Clock synchronization */

    String displayTime = "--:--:--";
    String displayDate = "Date unknown";

    void setDate(String date)
    {
        displayDate = date;
    }

    void setTime(String time)
    {
        displayTime = time;
    }

    /* Location */

    long latitude = 0;
    long longitude = 0;
    String displayLocation = "Location unknown";
    long altitude = 0; // altitude in mm
    long speed = 0; // speed in mm/s
    float speedKPH = 0;
    String displaySpeed = "- KM/h";

    void setLocation(long lat, long lon, long alt)
    {
        if (lat != latitude || lon != longitude)
        {
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "%ld, %ld", lat, lon);
            latitude = lat;
            longitude = lon;
            displayLocation = buffer;
        }
        if (alt != altitude)
        {
            altitude = alt;
        }
    }

    void setSpeed(long s)
    {
        if (s == speed)
        {
            return;
        }
        speed = s;
        speedKPH = 0.0036f * s;
        char buffer[16];
        snprintf(buffer, sizeof(buffer), "%.02f KPH", speedKPH);
        displaySpeed = buffer;
        // Update timers
        updateTimersSpeed();
    }

    /* Wi-Fi */

    bool wirelessConnected = false;
    String localIP = "unknown";
    String wirelessRSSI = "unknown";

    /* Message display */

    bool showMsg = false;
    String displayMsg = "";
    unsigned long messageEndTime = 0;

    // Display a message on screen
    void newMessage(String msg)
    {
        showMsg = true;
        displayMsg = msg;
        messageEndTime = millis() + MSG_DISPLAY_MS;
    }

    String getMessage()
    {
        // When there is a message to show, and within display time
        if (showMsg && (millis() < messageEndTime))
        {
            return displayMsg;
        }
        else
        {
            showMsg = false;
        }
        return "";
    }

    /* Display mode */

    DisplayMode displayMode = REGULAR;
    
    /* Timers */

    int displayTimerIndex = 0;
    double targetSpeeds[] = {60, 80, 100};
    static const int NUM_SPEED = 3;
    Timer *timers[NUM_SPEED];

    void initTimers() {
        for (int i = 0; i < NUM_SPEED; i ++) {
            timers[i] = new Timer(targetSpeeds[i]);
        }
    }

    void updateTimersSpeed() {
        for (int i = 0; i < NUM_SPEED; i ++) {
            timers[i]->updateSpeed(speedKPH);
        }
    }

    Timer *getTimer()
    {
        return timers[displayTimerIndex];
    }

};
