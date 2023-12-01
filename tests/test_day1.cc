#include <gtest/gtest.h>
#include "../src/day1.h"

TEST(Day1, Part1) {
    AOC23::Day1 d("../inputs/day1_test.txt");

    EXPECT_EQ(d.Part1(), 142);
    //EXPECT_EQ(124, 142);
}

TEST(Day1, Part2) {
    AOC23::Day1 d("../inputs/day1_part2_test.txt");
  
    EXPECT_EQ(d.Part2(), 281);
    //EXPECT_EQ(142, 142);
}