#ifndef AOC2023_DAYDAY_NUMBER_H
#define AOC2023_DAYDAY_NUMBER_H

#include "day.h"

namespace AOC23
{
    class DayDAY_NUMBER : public IDay
    {
        public:
            Day1(std::string fname);
            virtual int Part1();
            virtual int Part2();
    };

}
#endif // AOC2023_DAYDAY_NUMBER_H
