#ifndef AOC2023_DAY4_H
#define AOC2023_DAY4_H

#include "day.h"

namespace AOC23
{

    class CardGame {
    public:
        int id;
        std::vector<int> winners;
        std::vector<int> numbers;
        int corrects;
        CardGame() {};
        CardGame(std::string &source);
        int matches();
        int winning();
    };


    class Day4 : public IDay
    {
        public:
            Day4(std::string fname);
            virtual int Part1();
            virtual int Part2();
            std::vector<CardGame> games;
    };

}
#endif // AOC2023_DAY4_H
