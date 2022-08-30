#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include "time.h"
#include "config.h"
#include "ioControl.h"
#include "timer/timer.h"

namespace state
{

    /* Clock Display */

    extern String displayTime;
    extern String displayDate;
    extern void setTime(String time);
    extern void setDate(String date);

    /* GPS */

    extern long latitude, longitude, altitude;
    extern String displayLocation;
    extern void setLocation(long lat, long lon, long alt);
    extern long speed;
    extern float speedKPH;
    extern String displaySpeed;
    extern void setSpeed(long s);

    /* Wi-Fi */

    extern bool wirelessConnected;
    extern String localIP;
    extern String wirelessRSSI;

    /* Message display */

    extern bool showMsg;
    extern String displayMsg;
    extern unsigned long messageEndTime;
    extern void newMessage(String msg);
    extern String getMessage();

    enum DisplayMode
    {
        REGULAR,
        DEBUG
    };

    extern DisplayMode displayMode;

    /* Timer */
    static const double targetSpeeds[] = {60, 80, 100};
    static const int NUM_SPEED = 3;
    extern int displayTimerIndex;       // Which timer to display?
    extern Timer *timers[];             // Arr of timers
    extern void initTimers();
    extern void updateTimersSpeed();    // state internal use
    extern Timer *getTimer();           // get timer to display

    /* Update */

    extern void refresh();

}

#endif