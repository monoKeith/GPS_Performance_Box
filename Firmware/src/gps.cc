#include <gps.h>

namespace gps
{

    SFE_UBLOX_GNSS myGNSS;

    long lastTime = 0;

    void setup() {
        // debug serial port
        Serial.begin(BAUD_DEBUG);

        bool baudRateNeedUpdate = true;

        // conenct to module on serial 1
        Serial1.begin(BAUD_DEFAULT);
        while (!myGNSS.begin(Serial1)) {
            // Try target baud rate
            Serial.println(F("Default baud rate failed, trying target baud rate."));
            Serial1.updateBaudRate(BAUD_TARGET);
            if (myGNSS.begin(Serial1)) {
                baudRateNeedUpdate = false;
                break;
            }
            Serial.println(F("u-blox GNSS not connected to Seairl 1. Please check wiring. Try again in 5s."));
            delay(5000);
        }

        if (baudRateNeedUpdate) {
            // set baud rate to target
            myGNSS.setSerialRate(BAUD_TARGET);
            Serial1.updateBaudRate(BAUD_TARGET);
        }
        
        // Setup finish
        Serial.println(F("u-blox connected."));

        if (! myGNSS.setNavigationFrequency(GNSS_REFRESH_RATE))
        {
            Serial.println(F("Failed to update GNSS refresh rate"));
        }
    }

    void update() {

        if (millis() - lastTime > 20)
        {
            lastTime = millis();

            long latitude = myGNSS.getLatitude();
            Serial.print(F("Lat: "));
            Serial.print(latitude);

            long longitude = myGNSS.getLongitude();
            Serial.print(F(" Long: "));
            Serial.print(longitude);
            Serial.print(F(" (degrees * 10^-7)"));



            long altitude = myGNSS.getAltitude();
            Serial.print(F(" Alt: "));
            Serial.print(altitude);
            Serial.print(F(" (mm)"));

            byte SIV = myGNSS.getSIV();
            Serial.print(F(" SIV: "));
            Serial.print(SIV);

            Serial.println();
            Serial.print(myGNSS.getYear());
            Serial.print("-");
            Serial.print(myGNSS.getMonth());
            Serial.print("-");
            Serial.print(myGNSS.getDay());
            Serial.print(" ");
            Serial.print(myGNSS.getHour());
            Serial.print(":");
            Serial.print(myGNSS.getMinute());
            Serial.print(":");
            Serial.print(myGNSS.getSecond());

            char buffer[32];

            snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", myGNSS.getYear(), myGNSS.getMonth(), myGNSS.getDay());
            state::setDate(buffer);

            snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", myGNSS.getHour(), myGNSS.getMinute(), myGNSS.getSecond());
            state::setTime(buffer);
        }
    }
}