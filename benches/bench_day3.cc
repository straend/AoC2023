#include <benchmark/benchmark.h>
#include "../src/day3.h"

static void AOC23_Day3_part1(benchmark::State& state) {
  AOC23::Day3 a("../inputs/day3.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day3_part1);

static void AOC23_Day3_part2(benchmark::State& state) {
  AOC23::Day3 a("../inputs/day3.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day3_part2);
