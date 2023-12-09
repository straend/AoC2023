#ifndef AOC2023_DAY_H
#define AOC2023_DAY_H


#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <cassert>

namespace AOC23 {
    class IDay {
        public:
            ~IDay() {};
            virtual int Part1() = 0;
            virtual unsigned long long Part2() = 0;
            
        protected:
            void ReadFromFile(const std::string &file_name);
            std::vector<std::string> lines;
            std::string fname;
        
    };

}
#endif