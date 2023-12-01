#!/bin/env bash
day=$1
if [ -f "src/day$day.cc" ]; 
then
echo "File for day $day already exists"
else
echo "Adding day $day"
# Replace day number in template and create new day file
sed "s|\DAY_NUMBER|${day}|g" "template_day.cc" > "src/day$day.cc"
sed "s|\DAY_NUMBER|${day}|g" "template_day.h" > "src/day$day.h"

# Create Input files for easy filling
touch "inputs/day${day}_test.txt"
touch "inputs/day${day}.txt"

# Add benchmarks
sed "s|\DAY_NUMBER|${day}|g" "template_bench.cc" > "benches/bench_day${day}.cc"

# Add tests
sed "s|\DAY_NUMBER|${day}|g" "template_test.cc" > "tests/test_day${day}.cc"

# Add things to main.cc
include_line="#include \"src/day${day}.h\""
sed -i "/[[:blank:]]*\/\/ Include headers here/i ${include_line}" main.cc

if_statement="if(${day} == day) {\n\tAOC23::Day${day} d(\"../inputs/day${day}.txt\");\n\tpart1 = d.Part1();\n\tpart2 = d.Part2();\n}"
sed -i "/[[:blank:]]*\/\/ Include if-statement here/i ${if_statement}" main.cc

echo "Go get the problem: https://adventofcode.com/2023/day/${day}"
fi

