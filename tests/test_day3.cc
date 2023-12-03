#include <gtest/gtest.h>
#include "../src/day3.h"

TEST(Day3, Part1) {
    AOC23::Day3 d("../inputs/day3_test.txt");

    EXPECT_EQ(d.Part1(), 4361);
    
    d = AOC23::Day3("../inputs/day3.txt");
    EXPECT_GT(d.Part1(), 529105);
    EXPECT_EQ(d.Part1(), 530849);
    
}

TEST(Day3, Part2) {
    AOC23::Day3 d("../inputs/day3_test.txt");
    EXPECT_EQ(d.Part2(), 467835);
    d = AOC23::Day3("../inputs/day3.txt");
    EXPECT_EQ(d.Part2(), 84900879);
}
