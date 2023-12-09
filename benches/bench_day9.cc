#include <benchmark/benchmark.h>
#include "../src/day9.h"

static void AOC23_Day9_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day9 a("../inputs/day9.txt");
}
BENCHMARK(AOC23_Day9_parse);

static void AOC23_Day9_part1(benchmark::State& state) {
  AOC23::Day9 a("../inputs/day9.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day9_part1);

static void AOC23_Day9_part2(benchmark::State& state) {
  AOC23::Day9 a("../inputs/day9.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day9_part2);
