#include "state.h"

namespace state
{

    /* Clock synchronization */

    bool timeSyncRequired = true;

    String lastSyncTime = "never";

    bool clockInitialized = false;

    String displayTime = "--:--";
    String displayLocation = "Location unknown";
    String displayDate = "Date unknown";

    void setDate(String date)
    {
        displayDate = date;
    }

    // Format time display as string
    void setTime(String time)
    {
        displayTime = time;
    }

    /* Location */

    void setLocation(String location)
    {
        displayLocation = location;
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

    /* Switch */

    bool switchOn = false;

};
