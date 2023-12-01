cmake_minimum_required(VERSION 3.14)
project(aoc_2023)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0135 NEW)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_Declare(
    googlebenchmark
    URL https://github.com/google/benchmark/archive/refs/tags/v1.8.3.zip
)

FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(googlebenchmark)

enable_testing()

file(GLOB day_SRC
     "src/*.h"
     "src/*.cc"
     "main.cc"
)
file(GLOB day_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cc" "main.cc")

file(GLOB test_SRC
    "src/*.h"
    "src/*.cc"
    "tests/*.h"
    "tests/*.cc"
     
)
file(GLOB test_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cc" "tests/*.h" "tests/*.cc")

add_executable(aoc_tests ${test_SRC} )

file(GLOB benches_SRC
     "benches/*.h"
     "benches/*.cc"
)
file(GLOB benches_SRC CONFIGURE_DEPENDS "benches/*.h" "benches/*.cc" "src/*.h" "src/*.cc")

add_executable(benchmarks ${benches_SRC} )

add_executable(AOC ${day_SRC} )

target_link_libraries(
  aoc_tests
  GTest::gtest_main
)


target_link_libraries(
  benchmarks
  benchmark_main
)

include(GoogleTest)
gtest_discover_tests(aoc_tests)
