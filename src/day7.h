#ifndef AOC2023_DAY7_H
#define AOC2023_DAY7_H

#include "day.h"

namespace AOC23
{
    typedef enum{
        HIGH,
        PAIR,
        TWOPAIR,
        THREES,
        FULLHOUSE,
        FOURS,
        FIVES,
    } handvalue_t;
    

    class Hand{
        public:
        int cards[5];
        handvalue_t value;
        int bid;
        
        static handvalue_t for_cards(int cards[5], bool jokers=false);
        Hand(){};
        Hand(std::string &line, bool jokers=false);
        Hand(char l[5], bool jokers=false);

    };

    class Day7 : public IDay
    {
        public:
            Day7(std::string fname);
            virtual int Part1();
            virtual unsigned long long Part2();
        private:
            std::vector<Hand> hands;

    };

}
#endif // AOC2023_DAY7_H
