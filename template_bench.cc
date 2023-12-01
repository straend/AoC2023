#include <benchmark/benchmark.h>
#include "../src/dayDAY_NUMBER.h"

static void AOC23_DayDAY_NUMBER_part1(benchmark::State& state) {
  AOC23::DayDAY_NUMBER a("../inputs/dayDAY_NUMBER.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_DayDAY_NUMBER_part1);

static void AOC23_DayDAY_NUMBER_part2(benchmark::State& state) {
  AOC23::Day1 a("../inputs/dayDAY_NUMBER.txt");
  for (auto _ : state)
    a.Part1();
}

BENCHMARK(AOC23_DayDAY_NUMBER_part2);
