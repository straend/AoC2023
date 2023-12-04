
#include "day4.h"
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
#include <ranges>

using namespace AOC23;

Day4::Day4(std::string fname){
    this->ReadFromFile(fname);
    std::transform(
        lines.begin(), lines.end(), 
        std::back_inserter(games), 
        [](std::string &l){return CardGame(l);}
    );

}


int Day4::Part1(){
    int sum = std::accumulate(
        games.begin(), games.end(), 
        0, [](int tot, CardGame &g){ return tot+g.winning();}
    );
    
    return sum;
}

int Day4::Part2(){
    int sum = 0;
    
    std::vector<int> gg;
    std::transform(
        games.begin(), games.end(), 
        std::back_inserter(gg), 
        [](CardGame &g){return g.corrects;}
    );
    int cc= 0;
    int last = 0;

    int *arr = new int[gg.size()];
    int *p = arr;
    for(auto &c : std::ranges::views::reverse(gg)) *p++ = c;
    
    for(int i=0; i<gg.size(); i++){
        int v = arr[i];
        
        if(v>0){
            int prevs = 0;
            for (int a=0; a<v; a++){
                prevs+=arr[i-1-a];
            }
            v += prevs;
        }
        arr[i] = v;
    }

    int prevs = gg.size();
    for(int i=0; i<gg.size(); i++) prevs+=arr[i];
    
    return prevs;
}

CardGame::CardGame(std::string &source){
    size_t index_of = source.find("|");
    std::string part1 = source.substr(0, index_of);
    std::string part2 = source.substr(index_of+1);
    size_t index_of_ = part1.find(":");
    
    char *cstr = new char[index_of+1];
    strcpy(cstr, part1.c_str());
    char *ptr = strtok(cstr, ":");
    sscanf(ptr, "%*s %d" , &id);

    //std::cout <<  id <<std::endl;
    char *n = strtok(NULL, " ");
    while (n!=NULL){
        //std::cout << "\t"<<n <<std::endl;
        winners.push_back(atoi(n));
        n = strtok(NULL, " ");
    }
    cstr = new char[part2.length()+1];
    strcpy(cstr, part2.c_str());
    n = strtok(cstr, " ");
    while (n!=NULL){
        //std::cout << "\t"<<n <<std::endl;
        numbers.push_back(atoi(n));
        n = strtok(NULL, " ");
    }
    
    std::sort(numbers.begin(), numbers.end());
    std::sort(winners.begin(), winners.end());
    //ptr = strtok(ptr, "|");
    //ptr = strtok(NULL, "|");
    //std::cout <<  22 <<"\t< "<<ptr<<std::endl;
    corrects = matches();

};
int CardGame::matches(){
    std::vector<int> matching;
    std::set_intersection(
        winners.begin(), winners.end(),
        numbers.begin(), numbers.end(),
        std::back_inserter(matching)
    );
    return matching.size();
}
int CardGame::winning(){
    
    int winningnumbers = corrects;

    if (winningnumbers == 0) return 0;

    int res = 1;
    while(--winningnumbers){
        res *= 2;
    }
    return res;
}