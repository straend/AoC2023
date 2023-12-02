
#include "day.h"
using namespace AOC23;
#include <iterator>

void IDay::ReadFromFile(const std::string &file_name)
{
    std::ifstream read_file(file_name);
    assert(read_file.is_open());
    std::string line;
    while (std::getline(read_file, line)) {
        this->lines.push_back(line);
    }
    read_file.close();
}