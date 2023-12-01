#include <gtest/gtest.h>
#include "../src/dayDAY_NUMBER.h"

TEST(DayDAY_NUMBER, Part1) {
    AOC23::DayDAY_NUMBER d("../inputs/dayDAY_NUMBER_test.txt");

    EXPECT_EQ(d.Part1(), 142);
}

TEST(DayDAY_NUMBER, Part2) {
    AOC23::DayDAY_NUMBER d("../inputs/dayDAY_NUMBER_part2_test.txt");
  
    EXPECT_EQ(d.Part2(), 281);
}
