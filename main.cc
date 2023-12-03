
#include <iostream>

#include "src/all_days.h"

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
    if(2 == day) {
        //AOC23::Day2 d("../inputs/day2.txt");
        AOC23::Day2 d("../inputs/day2.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    if(3 == day) {
        AOC23::Day3 d("../inputs/day3.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    // Include if-statement here

    std::cout << "Part 1"<< std::endl << "\t" << part1 << std::endl;
    std::cout << "Part 2"<< std::endl << "\t" << part2 << std::endl;

}