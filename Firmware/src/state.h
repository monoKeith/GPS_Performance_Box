#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include "time.h"
#include "config.h"

namespace state
{

    /* Clock synchronization */

    extern String lastSyncTime;

    extern bool clockInitialized;
    extern String displayTime;
    extern String displayDate;
    extern void setTime(String time);
    extern void setDate(String date);
    extern bool timeSyncRequired;

    /* GPS */
    extern String displayLocation;
    extern void setLocation(String location);

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

    /* Switch */

    extern bool switchOn;

}

#endif