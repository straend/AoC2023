
#include "day6.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>
#include <cstring>
#include <numeric>

using namespace AOC23;

Day6::Day6(std::string fname){
    this->ReadFromFile(fname);
    
    
    for (auto & line : this->lines) {
        char *cstr = new char[line.size()+1];
        strcpy(cstr, line.c_str());
        char *ptr = strtok(cstr, ":");
        if (strcmp("Time", ptr) == 0){
            ptr = strtok(NULL, ":");
            std::string str = std::string(ptr);
            str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
            race.time = atoll(str.c_str());
        } else if (strcmp("Distance", ptr) == 0) {
            ptr = strtok(NULL, ":");
            std::string str = std::string(ptr);
            str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
            race.record = atoll(str.c_str());
        }
    }
}

int winners(race_t &r){
    const long long acc = 1;
    const long long start = 0;

    std::vector<long long> wins;

    for (long long speed=acc, t=1; t<r.time; t++, speed+=acc){
        if (speed * (r.time-t) > r.record){
            wins.push_back(t);
        }
    }

    return wins.size();
}

int Day6::Part1(){
    std::vector<race_t> races;

    int sum = 0;
    for (auto & line : this->lines) {
        char *cstr = new char[line.size()+1];
        strcpy(cstr, line.c_str());
        char *ptr = strtok(cstr, ":");
        if (strcmp("Time", ptr) == 0){
            ptr = strtok(NULL, " :");
            while(NULL!=ptr){
                race_t r;
                r.time = atoll(ptr);
                races.push_back(r);

                ptr = strtok(NULL, " ");
            }

        } else if (strcmp("Distance", ptr) == 0) {
            ptr = strtok(NULL, " :");
            auto it = races.begin();
            while(NULL!=ptr){
                race_t &r = *it++;
                r.record = atoll(ptr);
                ptr = strtok(NULL, " ");
            }
        }
    }

    std::vector<int> res;

    for (auto &r : races){
        res.push_back(winners(r));
    }
    return std::reduce(res.begin(), res.end(), 1, [](int a, int b) {return a*b;});
}

unsigned long long Day6::Part2(){
    return winners(race);
}
