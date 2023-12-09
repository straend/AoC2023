#ifndef AOC2023_DAY9_H
#define AOC2023_DAY9_H

#include "day.h"

namespace AOC23
{
    class Day9 : public IDay
    {
        public:
            Day9(std::string fname);
            virtual int Part1();
            virtual unsigned long long Part2();
            std::vector<std::vector<long long>> starts;
    };

}
#endif // AOC2023_DAY9_H
