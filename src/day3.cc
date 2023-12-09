
#include "day3.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>

using namespace AOC23;

Day3::Day3(std::string fname){
    this->ReadFromFile(fname);

    std::regex rgx("[0-9]+");
    int l = 0;
    for (auto & line : this->lines) {
        std::smatch res;
        size_t offset = 0;
        for (auto it = std::sregex_iterator(line.begin(), line.end(), rgx); it != std::sregex_iterator(); ++it){
            int start = it->position();
            int end = start + it->length() -1 ;
            
            std::smatch match = *it;
            int val = stoi(match.str());
            this->parts.push_back(EnginePart(l, start, end, val));
        }
        l++;
    }
}

bool EnginePart::IsValid(std::vector<std::string> &lines) {
    return this->CheckSameLine(lines) || this->CheckLineBelow(lines) || this->CheckLineAbove(lines);
}

bool EnginePart::CheckSameLine(std::vector<std::string> &lines) {
    
    // Before
    if (this->start > 0) {
        int char_check = lines.at(this->line).at(this->start-1);
        if (char_check != '.' && char_check < '0' || char_check > '9') return true;
    }
    
    // After
    if (this->end+1 < lines.at(this->line).length()) {
        int char_check = lines.at(this->line).at(this->end+1);
        if (char_check != '.' && char_check < '0' || char_check > '9') return true;
    }
    
    return false;
}
bool EnginePart::CheckLineAbove(std::vector<std::string> &lines) {
    if (this->line==0) return false;
    std::string &l = lines.at(this->line -1);
    
    int startfrom = this->start == 0?0:this->start-1;
    if (l.find_first_of(this->symbols, startfrom) <= this->end+1) return true;

    return false;
}
bool EnginePart::CheckLineBelow(std::vector<std::string> &lines) {
    if (this->line+1 >= lines.size()) return false;
    std::string &l = lines.at(this->line + 1);

    int startfrom = this->start == 0?0:this->start-1;
    if (l.find_first_of(this->symbols, startfrom) <= this->end+1) return true;


    return false;
}


int Day3::Part1(){
    int sum = 0;
 
    for (EnginePart &p : parts){
        if (p.IsValid(this->lines))
            sum+=p.value;
    }
 
    return sum;
}

unsigned long long Day3::Part2(){
    int sum = 0;
    
    int cl = 0;
    int rows = this->lines.size();
    int cols = this->lines.at(0).length();
    for (auto & line : this->lines) {
        // find * 
        int c=0;
        int p = line.find_first_of("*");
        
        while (std::string::npos != p){
            std::vector<int> gears;

            int s_line = cl > 0 ? cl-1 : 0;
            int s_col  = p > 0 ? p-1 : 0;
            int e_line = cl +1 >= rows ? rows-1: cl +1;
            int e_col = p +1 >= cols ? cols-1: p +1;
            
            for (EnginePart &p : this->parts){
                int li = p.line;
                int be = p.start;
                int end = p.end;
                if(li>=s_line && li <= e_line){
                    if ( (be >= s_col && be <= e_col) || (end >= s_col && end <= e_col)){
                        gears.push_back(p.value);
                    }
                }
                if (li > e_line) break;
            }
            if(gears.size() == 2){
                sum+= gears.at(0) * gears.at(1);
            }
            // Get next star
            p = line.find_first_of("*", p+1);
        }

        cl++;
        
    }
 
    return sum;
}
