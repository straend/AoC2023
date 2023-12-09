#include <benchmark/benchmark.h>
#include "../src/day4.h"

static void AOC23_Day4_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day4 a("../inputs/day4.txt");
}
BENCHMARK(AOC23_Day4_parse);

static void AOC23_Day4_part1(benchmark::State& state) {
  AOC23::Day4 a("../inputs/day4.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day4_part1);

static void AOC23_Day4_part2(benchmark::State& state) {
  AOC23::Day4 a("../inputs/day4.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day4_part2);
