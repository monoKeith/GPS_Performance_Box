#include <gps.h>

namespace gps
{

    SFE_UBLOX_GNSS myGNSS;

    void setup()
    {
        bool baudRateNeedUpdate = true;

        // conenct to module on serial 1
        Serial.begin(BAUD_DEFAULT);
        while (!myGNSS.begin(Serial))
        {
            // Try target baud rate
            Serial.println(F("Default baud rate failed, trying target baud rate."));
            Serial.updateBaudRate(BAUD_TARGET);
            if (myGNSS.begin(Serial))
            {
                baudRateNeedUpdate = false;
                break;
            }
            Serial.println(F("u-blox GNSS not connected to Seairl 1. Please check wiring. Try again in 5s."));
            delay(5000);
        }

        if (baudRateNeedUpdate)
        {
            // set baud rate to target
            myGNSS.setSerialRate(BAUD_TARGET);
            Serial.updateBaudRate(BAUD_TARGET);
        }

        // Setup finish
        Serial.println(F("u-blox connected."));

        if (!myGNSS.setNavigationFrequency(GNSS_REFRESH_RATE))
        {
            Serial.println(F("Failed to update GNSS refresh rate"));
        }
    }

    void updateLocation()
    {
        long latitude = myGNSS.getLatitude();
        long longitude = myGNSS.getLongitude();
        long altitude = myGNSS.getAltitude();
        state::setLocation(latitude, longitude, altitude);

        long speed = myGNSS.getGroundSpeed();
        state::setSpeed(speed);
    }

    void updateTime()
    {
        char buffer[32];

        snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", myGNSS.getYear(), myGNSS.getMonth(), myGNSS.getDay());
        state::setDate(buffer);

        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", myGNSS.getHour(), myGNSS.getMinute(), myGNSS.getSecond());
        state::setTime(buffer);
    }
}