#include <Arduino.h>
#include <monitor.h>
#include <gps.h>
#include <config.h>
#include "state.h"
#include "ioControl.h"

// Stack sizes
#define STACK_SIZE_SMALL 32768
#define STACK_SIZE_TINY 16384

void monitorThread(void *pvParameters)
{
    while (true)
    {
        // Refresh monitor, takes about 20ms?
        monitor::refresh();
        // Delay 50ms, ~14 fps
        delay(50);
    }
}

void gpsLocationThread(void *pvParameters)
{
    while (true)
    {
        gps::updateLocation();
        delay(20);
    }
}

void gpsTimeThread(void *pvParameters)
{
    while (true)
    {
        gps::updateTime();
        delay(200);
    }
}

void setup()
{
    // IO
    ioControl::setup();
    // Boot screen
    monitor::setup();
    monitor::drawBootScreen();
    // Timers
    state::initTimers();
    // Setup GPS
    gps::setup();
    // Start Threads
    xTaskCreate(gpsLocationThread, "GPS Location Thread", STACK_SIZE_SMALL, NULL, 10, NULL);
    xTaskCreate(gpsTimeThread, "GPS Time Thread", STACK_SIZE_SMALL, NULL, 5, NULL);
    xTaskCreate(monitorThread, "Monitor Thread", STACK_SIZE_SMALL, NULL, 2, NULL);
}

void loop()
{
    state::refresh();
    delay(50);
}
