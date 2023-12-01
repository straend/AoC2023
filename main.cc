
#include <iostream>

#include "src/day1.h"
// Include headers here

int main(int argc, char *argv[]){
    int part1 = 0;
    int part2 = 0;
    int day = atoi(argv[1]);
    std::cout << "AoC 2023 - Day " << day << std::endl;
    
    if(1 == day) {
        AOC23::Day1 d("../inputs/day1.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    // Include if-statement here

    std::cout << "Part 1"<< std::endl << "\t" << part1 << std::endl;
    std::cout << "Part 2"<< std::endl << "\t" << part2 << std::endl;

}