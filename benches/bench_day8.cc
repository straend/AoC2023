#include <benchmark/benchmark.h>
#include "../src/day8.h"

static void AOC23_Day8_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day8 a("../inputs/day8.txt");
}
BENCHMARK(AOC23_Day8_parse);

static void AOC23_Day8_part1(benchmark::State& state) {
  AOC23::Day8 a("../inputs/day8.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day8_part1);

static void AOC23_Day8_part2(benchmark::State& state) {
  AOC23::Day8 a("../inputs/day8.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day8_part2);
