#ifndef AOC2023_DAY1_H
#define AOC2023_DAY1_H

#include "day.h"

namespace AOC23
{
    class Day1 : public IDay
    {
        public:
            Day1(std::string fname);
            virtual int Part1();
            virtual int Part2();
    };

}
#endif // AOC2023_DAY1_H
