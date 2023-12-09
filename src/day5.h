#ifndef AOC2023_DAY5_H
#define AOC2023_DAY5_H

#include "day.h"
#include <unordered_map>

namespace AOC23
{
    struct maps_s
    {
        long long offset;
        long long src_s;
        long long src_e;
        long long trg_s;
        long long trg_e;
    };
    
    class Seed {
        public:
        long long id;
        std::unordered_map<std::string, long long> values;

        Seed(long long id) : id {id} {values["seed"] = id;};
        Seed() {};


    };
    class Mapping{
        public:
        std::string source;
        std::string target;
        
        std::vector<struct maps_s> pairs;
        std::vector<long long> source_start;
        std::vector<long long> source_end;
        std::vector<long long> target_start;
        std::vector<long long> target_end;
    };
    class Day5 : public IDay
    {
        public:
            Day5(std::string fname);
            virtual int Part1();
            virtual unsigned long long Part2();
            void debug();
        private:
            std::vector<Seed> seeds;
            std::vector<std::pair<long, long>> seeds2;
            //std::unordered_map<int, Seed> seeds;
            std::unordered_map<std::string, Mapping> maps;
            std::unordered_map<std::string, Mapping> maps2;


    };

}
#endif // AOC2023_DAY5_H
