
#include "day1.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>

using namespace AOC23;



int first_and_last_digit(const std::string &str){
    std::map<int, int> ind;
    std::map<int, int> indlast;

    const std::array<const char *, 10> number_keys = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const std::array<size_t, 10> key_len = {4,3,3,5,4,4,3,5,5,4};
    const std::string numbers = "0123456789";
    
    // start from 1 == skip zero
    for (std::size_t i=1, e=number_keys.size(); i!= e; ++i){
        int d = str.find(numbers[i]);
        int s = str.find(number_keys[i]);
        
        if (d==std::string::npos) d = 65000;
        if (s==std::string::npos) s = 65000;
        ind[i] = std::min(d, s);
    
        int ed = str.rfind(numbers[i]);
        int es = str.rfind(number_keys[i]);
        
        indlast[i] = std::max(ed, es);
        
    }
    std::pair<int, int> it = *min_element(ind.begin(), ind.end(),
                           [](const auto& l, const auto& r) { return l.second < r.second; });
    std::pair<int, int> it2 = *max_element(indlast.begin(), indlast.end(),
                           [](const auto& l, const auto& r) { return l.second < r.second; });
    
    std::string res = "";
    res+= numbers[it.first];
    res+=numbers[it2.first];
    
    return stoi(res);
}

Day1::Day1(std::string fname){
    this->ReadFromFile(fname);
}

int Day1::Part1(){
    int sum = 0;
    for (auto & line : this->lines) {
        size_t first_pos = line.find_first_of("0123456789");
        size_t last_pos = line.find_last_of("0123456789");
        std::string num = "";
        num += line[first_pos];
        num += line[last_pos];
        sum+=stoi(num);
    }
    return sum;
}

int Day1::Part2(){
    int sum = 0;
    for (auto & line_org : this->lines) {
        auto line = first_and_last_digit(line_org);
        sum+=line;
    }
    return sum;
}
