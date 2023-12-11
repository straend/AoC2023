#include <gtest/gtest.h>
#include "../src/day11.h"

TEST(Day11, Part1) {
    AOC23::Day11 d("../inputs/day11_test.txt");

    EXPECT_EQ(d.Part1(), 374);
}

TEST(Day11, Part2) {
    AOC23::Day11 d("../inputs/day11.txt");
    auto p2=d.Part2();
    EXPECT_LT(p2, 1421341907809);
                //1421349815618
    EXPECT_EQ(p2, 710674907809);
}
