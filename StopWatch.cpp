/*
 * start() : uses high res clock. takes current time on computer
  _start member is updated
 * stop() : uses high res clock. takes current time on computer
  _stop member is updated
 * timeMilliSec() : time in milliseconds = (_stop) - (_start)
  returns double, _milliSec is updated
 * timeSecond() : time in seconds = (_stop) - (_start)
  returns double, _seconds is updated
 */

#include "StopWatch.h"
#include <iostream>
#include <chrono>
#include <math.h>
using std::cout;
using std::endl;

StopWatch::StopWatch(){
    //cout << "Default constructor" << endl;
}

StopWatch::~StopWatch(){
    //cout << "Destructor is called on" << endl;
}

std::chrono::high_resolution_clock::time_point StopWatch::start(){
    auto chronoStartTime = std::chrono::high_resolution_clock::now();
    _start = chronoStartTime;
    return chronoStartTime;
}

std::chrono::high_resolution_clock::time_point StopWatch::stop(){
    auto chronoStopTime = std::chrono::high_resolution_clock::now();
    _stop = chronoStopTime;
    return _stop;
}

double StopWatch::timeMilliSec(){
    _milliSec = std::chrono::duration<double, std::milli>(_stop - _start).count();
    return _milliSec;
}

double StopWatch::timeSecond(){
    _seconds = std::chrono::duration<double>(_stop - _start).count();
    return _seconds;
}