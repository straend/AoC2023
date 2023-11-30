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
sed "s|\DAY_NUMBER|${day}|g" "template_bench.cc" > "benches/day${day}.cc"

echo "Go get the problem: https://adventofcode.com/2023/day/${day}"
fi
