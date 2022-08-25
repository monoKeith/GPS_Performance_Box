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

    DisplayMode displayMode = DEBUG;

};
