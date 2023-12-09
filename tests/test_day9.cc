#include <gtest/gtest.h>
#include "../src/day9.h"

TEST(Day9, Part1) {
    AOC23::Day9 d("../inputs/day9_test.txt");
    auto p1 = d.Part1();
    EXPECT_EQ(p1, 114);

    d = AOC23::Day9("../inputs/day9.txt");
    p1 = d.Part1();
    EXPECT_LT(p1, 1581681550);
}

TEST(Day9, Part2) {
    AOC23::Day9 d("../inputs/day9_test.txt");
  
    EXPECT_EQ(d.Part2(), 2);
}
