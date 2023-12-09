
#include "day9.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <cstring>
using namespace AOC23;

Day9::Day9(std::string fname){
    this->ReadFromFile(fname);
    
    for (auto & line : this->lines) {
        std::vector<long long> l;

        char cstr[line.size()+1];
        strcpy(cstr, line.c_str());
        char *ptr = strtok(cstr, " ");
        while(ptr!=NULL){
            l.push_back(atoll(ptr));
            ptr = strtok(NULL, " ");
        }
        starts.push_back(l);
    }
    
}

std::vector<long long> diff(std::vector<long long> &v)
{
    std::vector<long long> tmp;
    auto it = v.begin();
    auto last = *it;
    while(++it != v.end()){
        tmp.push_back(*it-last);
        last = *it;
    }
    return tmp;
}

int Day9::Part1(){
    std::vector<long long> predictions;
    
    std::vector<std::vector<std::vector<long long>>> paths;
    for (auto &s : starts) {
        std::vector<std::vector<long long>> tmp;
        // Loop until diff is 0 between steps
        for(auto x=s; !std::all_of(x.begin(), x.end(), [](auto v){return v == 0;}); tmp.push_back(x), x=diff(x));
        paths.push_back(tmp);
    }
 
    for (auto &p : paths) {
        // add last item in all rows to predictions
        
        std::transform(p.begin(), p.end(), std::back_inserter(predictions), [](auto &item){return item.back();});
    }

    return std::reduce(predictions.begin(), predictions.end());
}

unsigned long long Day9::Part2(){
    std::vector<long long> predictions;
    
    std::vector<std::vector<std::vector<long long>>> paths;
    // Exactly the same as in part 1
    for (auto &s : starts) {
        std::vector<std::vector<long long>> tmp;
        // Loop until diff is 0 between steps
        for(auto x=s; !std::all_of(x.begin(), x.end(), [](auto v){return v == 0;}); tmp.push_back(x), x=diff(x));
        paths.push_back(tmp);
    }
 
    for (auto &p : paths) {
        long long last = 0;
        for(auto it=p.rbegin(); it!=p.rend(); it++){
            last = (*it).front() - last;
        }
        predictions.push_back(last);
    }

    return std::reduce(predictions.begin(), predictions.end());
}
