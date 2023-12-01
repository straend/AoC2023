#include <benchmark/benchmark.h>
#include "../src/day1.h"

static void AOC23_Day1_part1(benchmark::State& state) {
  AOC23::Day1 a("../inputs/day1.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day1_part1);

static void AOC23_Day1_part2(benchmark::State& state) {
  AOC23::Day1 a("../inputs/day1.txt");
  for (auto _ : state)
    a.Part1();
}

BENCHMARK(AOC23_Day1_part2);
