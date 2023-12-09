
#include "day5.h"
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

using namespace AOC23;


Day5::Day5(std::string fname){
    this->ReadFromFile(fname);

    auto &l = lines.at(0);
    char *cstr = new char[l.size()+1];
    strcpy(cstr, l.c_str());
    char *ptr = strtok(cstr, ":");
    ptr = strtok(NULL, " ");
    while(NULL!=ptr){
        seeds.push_back(Seed(atoll(ptr)));
        ptr = strtok(NULL, " ");
    }
    delete []cstr;
    auto it = std::begin(lines);
    it++;
    bool has_header = false;
    Mapping map;
    for (auto end=std::end(lines); it != end; ++it){
        std::string &l = *it;
        if (l.length() == 0){
            if (has_header)
                maps[map.source] = map;
            has_header = false;
            continue;
        }
        if(l.at(0)>'9'){
            map = Mapping();
            //std::cout << "Header " << std::endl;
            char *cstr = new char[l.size()+1];
            strcpy(cstr, l.c_str());
            char *ptr = strtok(cstr, "- ");
            //std::cout << "  " << ptr << std::endl;
            map.source = ptr;
            ptr = strtok(NULL, "- ");
            ptr = strtok(NULL, "- ");
            map.target = ptr;
            has_header = true;
        } else {
            long long src, trg, len;
            sscanf(l.c_str(), "%lld %lld %lld", &trg, &src, &len);
            struct maps_s p;
            p.offset = trg - src;
            p.src_s = src;
            p.src_e = src+ len;
            p.trg_s = trg;
            p.trg_e = trg + len;

            map.pairs.push_back(p);
        }
    }

}
void Day5::debug() {

}
int Day5::Part1(){
    std::cout <<"seeds: "<< seeds.size()<<std::endl;
    bool has_location = false;

    auto &k = maps["seed"];
    while(!has_location){
        for (auto &s : seeds){
            long long trg = 0;
            long long src = s.values[k.source];
            //std::cout << k.source << ": " << s.id << " == " << src << std::endl;
            bool matched = false;
            for(auto &vl : k.pairs){
                if (src >= vl.src_s && src <= vl.src_e){
                    trg = src + vl.offset;
                    matched = true;
                    continue;
                }
            }
            if (!matched) trg = src;
            s.values[k.target] = trg;
        }
        if (k.target == "location")
            has_location = true;
        else {
            k = maps[k.target];
        }
    }
    
    std::sort(seeds.begin(), seeds.end(), [](Seed &s1, Seed &s2){
        return s1.values["location"] < s2.values["location"];
    });
    std::cout << seeds.at(0).values["seed"] << std::endl;
    return seeds.at(0).values["location"];
    
}

unsigned long long Day5::Part2(){
    std::cout <<"seeds: "<< seeds.size()<<std::endl;
    
    bool has_location = false;
    
    std::unordered_map<std::string, Mapping> maps2;

    for (auto const&[k, v] : maps){
        maps2[v.target] = v;
    }


    bool has_seed = false;

    auto &k = maps2["location"];
    for (auto &j : k.pairs){
        std::cout << j.trg_s << " - " <<   j.trg_e << std::endl;


    }



    for (auto const&[k, v] : maps2){
        std::cout << k << std::endl;

    }
    
    //std::sort(seeds.begin(), seeds.end(), [](Seed &s1, Seed &s2){
    //    return s1.values["location"] < s2.values["location"];
    //});
    //std::cout << seeds.at(0).values["seed"] << std::endl;
    //return seeds.at(0).values["location"];
    return 0;
}
