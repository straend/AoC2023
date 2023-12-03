#ifndef AOC2023_DAY3_H
#define AOC2023_DAY3_H

#include "day.h"

namespace AOC23
{

class EnginePart {
public:
    int line;
    int start;
    int end;
    int value;
    EnginePart (int line, int start, int end, int value) 
        : line {line}, start {start}, end {end}, value {value} {};

    bool IsValid(std::vector<std::string> &lines);

private:
    bool CheckSameLine(std::vector<std::string> &lines);
    bool CheckLineAbove(std::vector<std::string> &lines);
    bool CheckLineBelow(std::vector<std::string> &lines);
    const std::string symbols = "!\"#$%&'()*+,-/:;<=>?@[\\]^_`{|}~";
};


    class Day3 : public IDay
    {
    public:
        Day3(std::string fname);
        virtual int Part1();
        virtual int Part2();
    private:
        std::vector<EnginePart> parts;

    };

}
#endif // AOC2023_DAY3_H
