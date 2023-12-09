#include <benchmark/benchmark.h>
#include "../src/day5.h"

static void AOC23_Day5_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day5 a("../inputs/day5.txt");
}
BENCHMARK(AOC23_Day5_parse);

static void AOC23_Day5_part1(benchmark::State& state) {
  AOC23::Day5 a("../inputs/day5.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day5_part1);

static void AOC23_Day5_part2(benchmark::State& state) {
  AOC23::Day5 a("../inputs/day5.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day5_part2);
