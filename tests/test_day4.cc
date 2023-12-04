#include <gtest/gtest.h>
#include "../src/day4.h"

TEST(Day4, Part1) {
    AOC23::Day4 d("../inputs/day4_test.txt");

    EXPECT_EQ(d.Part1(), 13);
    
    d = AOC23::Day4("../inputs/day4.txt");

    EXPECT_EQ(d.Part1(), 24733);
    
}

TEST(Day4, Part2) {
    AOC23::Day4 d("../inputs/day4_test.txt");
  
    EXPECT_EQ(d.Part2(), 30);
    
    d = AOC23::Day4("../inputs/day4.txt");
    EXPECT_EQ(d.Part2(), 5422730);
    
}
