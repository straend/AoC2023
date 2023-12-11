#include <gtest/gtest.h>
#include "../src/day10.h"

TEST(Day10, Part1) {
    AOC23::Day10 d("../inputs/day10_test.txt");
    EXPECT_EQ(d.Part1(), 4);
    d = AOC23::Day10("../inputs/day10.txt");
    EXPECT_EQ(d.Part1(), 7012);
}

TEST(Day10, Part2) {
    AOC23::Day10 d("../inputs/day10_test.txt");
  
    EXPECT_EQ(d.Part2(), 281);
}
