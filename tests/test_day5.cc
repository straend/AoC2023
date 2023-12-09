#include <gtest/gtest.h>
#include "../src/day5.h"

TEST(Day5, Part1) {

    AOC23::Day5 d("../inputs/day5_test.txt");
    EXPECT_EQ(d.Part1(), 35);

    //d = AOC23::Day5("../inputs/day5.txt");
    //d.debug();

    ///EXPECT_NE(d.Part1(), -2124951024);
}

TEST(Day5, Part2) {
    AOC23::Day5 d("../inputs/day5_test.txt");
  
    EXPECT_EQ(d.Part2(), 46);
}
