# Advent of Code 2023

### Usage
Add days with `./add_day.sh 1` where 1 is day to add.

This will add a src file and header for the day and a benchmark file.

Building using cmake: `cmake -S . -B build` 
then enter build dir and run `cmake --build .`

Wich will generate `benchmarks` and `aoc_tests`

`./aoc_tests --gtest_filter=Day1`
`./benchmarks --benchmark_filter=Day1`


**Happy coding!**