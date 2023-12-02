#include <benchmark/benchmark.h>
#include "../src/day2.h"

static void AOC23_Day2_parsing(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day2 a("../inputs/day2.txt");
}

BENCHMARK(AOC23_Day2_parsing);

static void AOC23_Day2_part1(benchmark::State& state) {
  AOC23::Day2 a("../inputs/day2.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day2_part1);

static void AOC23_Day2_part2(benchmark::State& state) {
  AOC23::Day2 a("../inputs/day2.txt");
  for (auto _ : state)
    a.Part1();
}

BENCHMARK(AOC23_Day2_part2);
