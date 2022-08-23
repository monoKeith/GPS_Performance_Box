#include <Arduino.h>
#include <monitor.h>
#include <gps.h>
#include <config.h>

// Stack sizes
#define STACK_SIZE_SMALL 32768
#define STACK_SIZE_TINY 16384

void monitorThread(void *pvParameters)
{
    while (true)
    {
        // Delay for 50ms, ~14 fps
        delay(50);
        // Refresh monitor, takes about 20ms?
        monitor::refresh();
    }
}

void setup()
{
    // Boot screen
    monitor::setup();
    monitor::drawBootScreen();
    // Load GPS
    gps::setup();
    // Run tasks
    xTaskCreate(monitorThread,
                "MonitorThread",
                STACK_SIZE_SMALL,
                NULL,
                2,
                NULL);
}

void loop()
{
    gps::update();
}

