
#include <iostream>

#include "src/all_days.h"

int main(int argc, char *argv[]){
    int part1 = 0;
    unsigned long long part2 = 0;
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
    if(4 == day) {
        AOC23::Day4 d("../inputs/day4.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    if(5 == day) {
        AOC23::Day5 d("../inputs/day5.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    if(6 == day) {
        AOC23::Day6 d("../inputs/day6.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    if(7 == day) {
        AOC23::Day7 d("../inputs/day7.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    if(8 == day) {
        AOC23::Day8 d("../inputs/day8.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    if(9 == day) {
        AOC23::Day9 d("../inputs/day9.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    if(10 == day) {
        AOC23::Day10 d("../inputs/day10.txt");
        part1 = d.Part1();
        part2 = d.Part2();
    }
    // Include if-statement here

    std::cout << "Part 1"<< std::endl << "\t" << part1 << std::endl;
    std::cout << "Part 2"<< std::endl << "\t" << part2 << std::endl;

}