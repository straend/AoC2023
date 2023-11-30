#include <benchmark/benchmark.h>

// Define another benchmark
static void BM_DayDAY_NUMBER_part1(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_DayDAY_NUMBER_part1);

static void BM_DayDAY_NUMBER_part2(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_DayDAY_NUMBER_part2);

