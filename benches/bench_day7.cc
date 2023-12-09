#include <benchmark/benchmark.h>
#include "../src/day7.h"

static void AOC23_Day7_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day7 a("../inputs/day7.txt");
}
BENCHMARK(AOC23_Day7_parse);

static void AOC23_Day7_part1(benchmark::State& state) {
  AOC23::Day7 a("../inputs/day7.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day7_part1);

static void AOC23_Day7_part2(benchmark::State& state) {
  AOC23::Day7 a("../inputs/day7.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day7_part2);
