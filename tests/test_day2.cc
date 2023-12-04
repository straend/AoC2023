#include <gtest/gtest.h>
#include "../src/day2.h"

TEST(Day2, Part1) {
    AOC23::Day2 d("../inputs/day2_test.txt");

    EXPECT_EQ(d.Part1(), 8);
}

TEST(Day2, Part2) {
    AOC23::Day2 d("../inputs/day2_test.txt");
  
    EXPECT_EQ(d.Part2(), 2286);
}
