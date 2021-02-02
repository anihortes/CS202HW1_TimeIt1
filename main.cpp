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
using std::reverse;
#include <fstream>
using std::ifstream;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <map>
using std::map;
using std::pair;
#include <string>
using std::string;

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

void timingRun(const long long &vectorSize,
               double &sortTime, double &searchTime, double &binarySearchTime, double &reverseTime){
    vector<long long> timingVector = randomVector(vectorSize);
    StopWatch timer;
    random_device randomStringInFile;
    mt19937 gen(randomStringInFile());
    uniform_int_distribution<>dis(1,vectorSize);

    timer.start();
    sort(timingVector.begin(), timingVector.end());
    timer.stop();
    sortTime = timer.timeMilliSec();

    long long  needle[] = {timingVector[timingVector.size()-2], timingVector[timingVector.size()-1]};
    timer.start();
    search(timingVector.begin(), timingVector.end(), needle, needle+1);
    timer.stop();
    searchTime = timer.timeMilliSec();

    timer.start();
    binary_search(timingVector.begin(), timingVector.end(), 562356);
    timer.stop();
    binarySearchTime = timer.timeMilliSec();

    timer.start();
    reverse(timingVector.begin(), timingVector.end());
    timer.stop();
    reverseTime = timer.timeMilliSec();
}

void writeToExcel(const vector<pair<string,double>> &containerTimings){
    std::filebuf fileBuffer;
    fileBuffer.open ("CS201HW1.csv", std::ios::out);
    std::ostream myFile(&fileBuffer);
    if(!myFile){
        cout << "file not found." << endl;
    }
    else {
        for(const auto &[s,i] : containerTimings)
            myFile << s << ","<<i<<endl;
        fileBuffer.close();
    }
}

int main() {
    vector<pair<string, double>> timingData;
    double sortTime = 1;
    double searchTime=2;
    double binarySearchTime=3;
    double reverseTime=4;
    string sortString = "time to sort ";
    string searchString = "time to find using search function ";
    string binarySearchString = "time to find using binary_search function ";
    string reverseString = "time to reverse ";
    for (auto i = 1; i < 9; ++i){
        for(long long j = 10; j < 1000000000;){
            j = pow(j,i);
            timingData.push_back(std::pair(std::to_string(j) + " long container:",0));
            timingRun(j, sortTime, searchTime, binarySearchTime, reverseTime);
            timingData.push_back(pair(sortString, sortTime));
            timingData.push_back(pair(searchString, searchTime));
            timingData.push_back(pair(binarySearchString, binarySearchTime));
            timingData.push_back(pair(reverseString, reverseTime));
            break;
        }
    }
    writeToExcel((timingData));
    return 0;
}

