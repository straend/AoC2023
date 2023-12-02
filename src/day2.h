#ifndef AOC2023_DAY2_H
#define AOC2023_DAY2_H

#include "day.h"

namespace AOC23
{
    class GameThrow {
        public:
        int red;
        int green;
        int blue;
        GameThrow(int red, int green, int blue)
            : red {red}, green {green}, blue {blue}
            {

            };
        
    };

    class CubeGame {
        private:
            std::vector<GameThrow> throws;
        public:
            int id;
            bool validThrows(int red, int green, int blue);
            int powerCubes();

        
            CubeGame(int id): id {id} {};
            // Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
            CubeGame(const std::string source);
    };

    class Day2 : public IDay
    {
        private:
            std::vector<CubeGame> games;
        public:
            Day2(std::string fname);
            virtual int Part1();
            virtual int Part2();
    };

}
#endif // AOC2023_DAY2_H
