
#include "day8.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <numeric>
#include <unordered_set>

using namespace AOC23;

Day8::Day8(std::string fname){
    this->ReadFromFile(fname);
}

int Day8::Part1(){
    int sum = 0;
    std::string dirs = lines.at(0);
    std::unordered_map<std::string, std::pair<std::string, std::string>> map;
    auto it = lines.begin();
    it++;it++;
    while(it != lines.end()){
        std::string &l = *it;
        char *cstr = new char[l.size()+1];
        strcpy(cstr, l.c_str());
        char *key = strtok(cstr, " =,()");
        
        char *left = strtok(NULL, " =,()");
        char *right = strtok(NULL, " =,()");
        map[key] = std::pair(left, right);
        it++;
    }
    auto d = dirs.begin();
    std::string now = "AAA";
    while (now != "ZZZ"){
        if (*d=='L'){
            now = map[now].first;
        } else {
            now = map[now].second;

        }
        sum++;
        d++;
        if (d==dirs.end()) d = dirs.begin();
    }
    return sum;
}

unsigned long long Day8::Part2(){
    unsigned long long sum = 0;
    std::unordered_map<std::string, std::pair<std::string, std::string>> map;
    auto it = lines.begin();
    std::string dirs = *it;
    it++;it++;
    while(it != lines.end()){
        std::string &l = *it;
        char *cstr = new char[l.size()+1];
        strcpy(cstr, l.c_str());
        char *key = strtok(cstr, " =,()");

        char *left = strtok(NULL, " =,()");
        char *right = strtok(NULL, " =,()");
        map[key] = std::pair(left, right);
        it++;
    }
    
    auto d = dirs.begin();
    std::vector<std::string> starts;
    for(const auto &[k, v] : map){
        if (k.at(2) == 'A') {
            starts.push_back(k);
        }
    }
    std::unordered_set<unsigned long long> sols;
    for (int i=0; i< starts.size(); i++){
        std::string s = starts.at(i);
        std::string now;
        unsigned long long iter = 1;
        int step=0;
        int last=0;
        int last_step = 0;
        bool finnish = false;
        while(!finnish){
            now = map[s].first;
            if (*d == 'R') now = map[s].second;
            
            if (now.at(2) == 'Z'){
                step = iter - last;
                if (last_step && step == last_step) {
                    finnish = true;
                } else {
                    sols.insert(iter);
                }
                last_step = step;
                last = iter;
            }
            s=now;
            iter++;
            d++;
            if (d==dirs.end()) d=dirs.begin();
        }
    }
    sum = std::reduce(sols.begin(), sols.end(), *sols.begin(), [](auto a, auto b) {return std::lcm(a,b);});
    
    return sum;
}
