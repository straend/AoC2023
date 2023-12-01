
#include "day.h"
using namespace AOC23;
#include <iterator>

void IDay::ReadFromFile(const std::string &file_name)
{
    std::ifstream read_file(file_name);
    assert(read_file.is_open());

    std::copy(std::istream_iterator<std::string>(read_file), std::istream_iterator<std::string>(),
        std::back_inserter(this->lines));

    read_file.close();
}