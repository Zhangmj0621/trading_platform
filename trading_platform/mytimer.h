#ifndef MYTIMER_H
#define MYTIMER_H


#include <chrono>
#include <thread>
#include "event.h"

class MyTimer
{
private:
    uint64_t interval;
    unsigned defaultTime;
    unsigned currentTime;
    std::thread TimerThread;
public:
    event<EventHandler> TimerTickEvent;
    event<EventHandler> TimerDoneEvent;
public:
    MyTimer() {
        this->interval = 1000;
        this->defaultTime = this->currentTime = 0;
    }
    MyTimer(uint64_t interval) {
        this->interval = interval;
        this->defaultTime = this->currentTime = 0;
    }
    MyTimer(uint64_t interval, unsigned ticks)
    {
        this->interval = interval;
        this->defaultTime = this->currentTime = ticks;
    }


    void SetTime(unsigned ticks)
    {
        this->defaultTime = ticks;
    }

    void Start()
    {
        this->currentTime = this->defaultTime;
        this->Runner();
    }

private:
    void Runner()
    {
        while (1)
        {
            --this->currentTime;
            std::this_thread::sleep_for(std::chrono::milliseconds(this->interval));
            if (NULL != TimerTickEvent)
                ((EventHandler)TimerTickEvent)();
        }
        if (NULL != TimerDoneEvent)
            ((EventHandler)TimerDoneEvent)();
    }
};

extern void runtimer();

extern void TimerTick();

extern void TimerDone();
#endif // MYTIMER_H
