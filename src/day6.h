#ifndef AOC2023_DAY6_H
#define AOC2023_DAY6_H

#include "day.h"

namespace AOC23
{
    typedef struct {
        long long time;
        long long record;
    } race_t;

    class Day6 : public IDay
    {
        public:
            Day6(std::string fname);
            virtual int Part1();
            virtual unsigned long long Part2();
        private:
            race_t race;
    };

}
#endif // AOC2023_DAY6_H
