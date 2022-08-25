#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include "time.h"
#include "config.h"

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
        DEBUG,
        OFF
    };
    extern DisplayMode displayMode;

}

#endif