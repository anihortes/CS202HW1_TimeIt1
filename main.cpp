//#include "StopWatch.h"
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

vector<int> randomVector(){
    vector <int> randomVector;
    for (auto i =0; i <100; ++i){
        randomVector.push_back(i);
    }
    random_device randomStringInFile;
    mt19937 gen(randomStringInFile());
    uniform_int_distribution<>dis(1,100);
    for(auto i : randomVector){
        randomVector[i] = rand() % 100;
        cout << randomVector[i] << endl;
    }
    return randomVector;
}

int main() {
    randomVector();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

