#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include "config.h"

class Timer
{
public:
    Timer(double targetSpeed);
    ~Timer();

    void updateSpeed(double newSpeed);

    bool rolling();

    enum TimerState {
        WAITING,    // Waiting to start timer
        TICKING,    // Timer started
        ACHIEVED,   // Timer stopped, result available
        RESET       // Timer got resetted
    };
    
    String getTargetSpeed();
    String getPrevious();
    String getBest();
    String getDuration();

    void reset();

private:
    String targetSpeed_s;
    bool noRecord;
    double targetSpeed, curSpeed;
    TimerState state;
    unsigned long startTime, duration;
    unsigned long best, previous;
};

#endif