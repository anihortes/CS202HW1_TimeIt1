//
// Created by A. Harrison Owen on 1/31/2021.
//

#ifndef CS202HW1_TIMEIT1_STOPWATCH_H
#define CS202HW1_TIMEIT1_STOPWATCH_H


#include <iostream>
#include <chrono>
#include <ctime>

class StopWatch{
public:
    StopWatch();
    StopWatch(const std::chrono::high_resolution_clock &);
    ~StopWatch();

    std::chrono::high_resolution_clock::time_point start();
    std::chrono::high_resolution_clock::time_point stop();
    double timeMilliSec();
    double timeSecond();
private:
    std::chrono::high_resolution_clock::time_point _start;
    std::chrono::high_resolution_clock::time_point _stop;
    double _milliSec;
    double _seconds;
};


#endif //CS202HW1_TIMEIT1_STOPWATCH_H
