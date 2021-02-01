#include "StopWatch.h"
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::search;
using std::binary_search;
using std::rotate;
#include <fstream>
using std::ifstream;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <map>
using std::map;

vector<long long> randomVector(const int &vectorSize){
    vector <long long> randomVector;
    for (auto i =0; i <vectorSize; ++i){
        randomVector.push_back(i);
       //cout << "vector: " << randomVector[i] << endl;
    }
    random_device randomStringInFile;
    mt19937 gen(randomStringInFile());
    uniform_int_distribution<>dis(1,vectorSize);
    for(auto i : randomVector){
        randomVector[i] = dis(gen);
    }
    return randomVector;
}

int main() {
    long long vectorSize = 10000000;
    vector<long long> timingVector = randomVector(vectorSize);
    StopWatch timer;
    random_device randomStringInFile;
    mt19937 gen(randomStringInFile());
    uniform_int_distribution<>dis(1,vectorSize);
    sort(timingVector.begin(), timingVector.end());
    long long  needle[] = {timingVector[timingVector.size()-2], timingVector[timingVector.size()-1]};
    timer.start();
    search(timingVector.begin(), timingVector.end(), needle, needle+1);
    timer.stop();
    cout << "time to find using search function: " << timer.timeMilliSec() << endl;
    timer.start();
    binary_search(timingVector.begin(), timingVector.end(), 562356);
    long long temp = timingVector[dis(gen)];
    timer.stop();
    cout << "time to find using search function: " << timer.timeMilliSec() << endl;
    return 0;
}

