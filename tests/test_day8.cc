#include <gtest/gtest.h>
#include "../src/day8.h"

TEST(Day8, Part1) {
    AOC23::Day8 d("../inputs/day8_test.txt");
    EXPECT_EQ(d.Part1(), 2);

    d = AOC23::Day8("../inputs/day8_test2.txt");
    EXPECT_EQ(d.Part1(), 6);
}

TEST(Day8, Part2) {
    AOC23::Day8 d("../inputs/day8_test_part2.txt");
    EXPECT_EQ(d.Part2(), 6);
  
    d=AOC23::Day8("../inputs/day8.txt");
    unsigned long long res = d.Part2();
    EXPECT_LT(res, 18446744072971369796);
    EXPECT_GT(res, 1191105057);
    EXPECT_EQ(res, 12324145107121);
}
