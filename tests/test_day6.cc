#include <gtest/gtest.h>
#include "../src/day6.h"

TEST(Day6, Part1) {
    AOC23::Day6 d("../inputs/day6_test.txt");

    EXPECT_EQ(d.Part1(), 288);
}

TEST(Day6, Part2) {
    AOC23::Day6 d("../inputs/day6_test.txt");
  
    EXPECT_EQ(d.Part2(), 71503);
}
