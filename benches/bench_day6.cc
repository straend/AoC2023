#include <benchmark/benchmark.h>
#include "../src/day6.h"

static void AOC23_Day6_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day6 a("../inputs/day6.txt");
}
BENCHMARK(AOC23_Day6_parse);

static void AOC23_Day6_part1(benchmark::State& state) {
  AOC23::Day6 a("../inputs/day6.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day6_part1);

static void AOC23_Day6_part2(benchmark::State& state) {
  AOC23::Day6 a("../inputs/day6.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day6_part2);
