#include <benchmark/benchmark.h>
#include "../src/day11.h"

static void AOC23_Day11_parse(benchmark::State& state) {
  for (auto _ : state)
    AOC23::Day11 a("../inputs/day11.txt");
}
BENCHMARK(AOC23_Day11_parse);

static void AOC23_Day11_part1(benchmark::State& state) {
  AOC23::Day11 a("../inputs/day11.txt");
  for (auto _ : state)
    a.Part1();
}
BENCHMARK(AOC23_Day11_part1);

static void AOC23_Day11_part2(benchmark::State& state) {
  AOC23::Day11 a("../inputs/day11.txt");
  for (auto _ : state)
    a.Part2();
}

BENCHMARK(AOC23_Day11_part2);
