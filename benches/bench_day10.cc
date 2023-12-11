#include <benchmark/benchmark.h>
#include "../src/day10.h"

static void AOC23_Day10_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day10 a("../inputs/day10.txt");
}
BENCHMARK(AOC23_Day10_parse);

static void AOC23_Day10_part1(benchmark::State& state) {
  AOC23::Day10 a("../inputs/day10.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day10_part1);

static void AOC23_Day10_part2(benchmark::State& state) {
  AOC23::Day10 a("../inputs/day10.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day10_part2);
