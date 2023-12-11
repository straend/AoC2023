#ifndef AOC2023_DAY10_H
#define AOC2023_DAY10_H

#include "day.h"

namespace AOC23
{
    typedef struct {
        size_t x;
        size_t y;
    } point_t;

    typedef enum {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        GROUND,
        STARTING,
        NONE,
    } dir_t;

    class Day10 : public IDay
    {
        public:
            Day10(std::string fname);
            virtual int Part1();
            virtual unsigned long long Part2();
        private:
            dir_t CheckPoint(point_t p);
            dir_t ValidMove(point_t pos, dir_t towards, dir_t from);
            dir_t NextMove(point_t pos, dir_t from);

            char CharAt(point_t pos);
            char CharAt(size_t x, size_t y);

    };

}
#endif // AOC2023_DAY10_H
