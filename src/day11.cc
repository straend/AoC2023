
#include "day11.h"
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

using namespace AOC23;

Day11::Day11(std::string fname){
    this->ReadFromFile(fname);
}

int Day11::Part1(){
    int sum = 0;
    int row = 0;
    std::vector<int> cols;
    std::vector<int> rows;
    for(int col=0; col<lines.front().size(); col++){
        bool empty = true;
        for (auto & line : this->lines) {
            if(line.at(col) == '#'){
                empty = false;
                break;
            }
        }
        if(empty)
            cols.push_back(col + cols.size());

    }
    for (auto & line : this->lines) {
        if(line.find('#') == std::string::npos){
            rows.push_back(row + rows.size());
        }
        row++;
    }

    for(auto col : cols){
        //std::cout << "Expand col " << col << std::endl;
        for (auto & line : this->lines) {
            line.insert(line.begin()+col, '.');
        }

    }
    for(auto row : rows){
        //std::cout << "Expand row " << row << std::endl;
        lines.insert(lines.begin()+row, lines.at(row));
    }
   

    std::vector<std::pair<int, int>> galaxies;
    row=0;
    int col=0;
    for (auto & line : this->lines) {
        col=0;
        for(auto &c : line){
            if(c=='#')
                galaxies.push_back(std::pair(row, col));
            col++;
        }
        row++;
    }
    int c=0;
    for (auto &g : galaxies) {
        //std::cout << g.first << " " << g.second << std::endl;
        auto it = galaxies.begin() + c + 1;
        while(it!=galaxies.end()){
            //std::cout << "\t" <<(*it).first << " " << (*it).second << "\t"; //std::endl;
            int xx = (*it).first - g.first;
            int yy = (*it).second - g.second;
            if (xx<0) xx=-xx;
            if (yy<0) yy=-yy;
            
            //std::cout << xx << " " << yy << " " << xx+yy << std::endl;
            sum+= xx+yy;

            it++;
        }
        
        c++;
    }
    return sum;
}

unsigned long long Day11::Part2(){
    const int TIMES = 1000000;
    unsigned long long sum = 0;
    
    int row = 0;
    std::vector<int> cols;
    std::vector<int> rows;
    // Find empty columns
    for(int col=0; col<lines.front().size(); col++){
        bool empty = true;
        for (auto & line : this->lines) {
            if(line.at(col) == '#'){
                empty = false;
                break;
            }
        }
        if(empty)
            cols.push_back(col);
    }
    // Find empty rows
    for (auto & line : this->lines) {
        if(line.find('#') == std::string::npos){
            rows.push_back(row);
        }
        row++;
    }
    
    std::vector<std::pair<int, int>> galaxies;
    row=0;
    int col=0;
    for (auto & line : this->lines) {
        col=0;
        for(auto &c : line){
            if(c=='#'){
                int extra_cols = std::count_if(cols.begin(), cols.end(), [col](auto c){return c<col;});
                int extra_rows = std::count_if(rows.begin(), rows.end(), [row](auto r){return r<row;});
                galaxies.push_back(std::pair(
                    row+(extra_rows*(TIMES-1)), col+(extra_cols*(TIMES-1))
                ));
            }
            col++;
        }
        row++;
    }
    // Skip self
    int c=1;
    for (auto &g : galaxies) {
        //std::cout << g.first << " " << g.second << std::endl;
        auto it = galaxies.begin() + c;
        for(auto it = galaxies.begin()+c; it!=galaxies.end(); it++){
            long long xx = (*it).first - g.first;
            long long yy = (*it).second - g.second;
            if (xx<0) xx=-xx;
            if (yy<0) yy=-yy;
            sum+= (xx+yy);
        }
        
        c++;
    }
    std::cout << sum << std::endl;
    return sum;
}
