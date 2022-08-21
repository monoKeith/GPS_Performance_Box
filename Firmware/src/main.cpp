#include <Arduino.h>
#include <monitor.h>
#include <gps.h>
#include <config.h>

void setup()
{
    monitor::setup();
    monitor::drawBootScreen();
    gps::setup();
}

void loop()
{
    
    // put your main code here, to run repeatedly:
}