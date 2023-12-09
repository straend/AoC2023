#include <gtest/gtest.h>
#include "../src/day7.h"
#include <string>

TEST(Day7, Unit) {
    AOC23::Hand h("QQJ9J", true);
    EXPECT_EQ(h.value, AOC23::FOURS);
    
    h = AOC23::Hand("QQJ9J", true);
    EXPECT_EQ(h.value, AOC23::FOURS);
    
    h = AOC23::Hand("AAA33", true);
    EXPECT_EQ(h.value, AOC23::FULLHOUSE);
    
    h = AOC23::Hand("AA33J", true);
    EXPECT_EQ(h.value, AOC23::FULLHOUSE);
    
    h = AOC23::Hand("QQJQJ", true);
    EXPECT_EQ(h.value, AOC23::FIVES);
    
    h = AOC23::Hand("44945", true);
    EXPECT_EQ(h.value, AOC23::THREES);

    h = AOC23::Hand("56655", true);
    EXPECT_EQ(h.value, AOC23::FULLHOUSE);

    
}

TEST(Day7, Part1) {
    AOC23::Day7 d("../inputs/day7_test.txt");

    EXPECT_EQ(d.Part1(), 6440);
}

TEST(Day7, Part2) {
    AOC23::Day7 d("../inputs/day7_test.txt");
  
    EXPECT_EQ(d.Part2(), 5905);
    
    
    d = AOC23::Day7("../inputs/day7.txt");
    EXPECT_LT(d.Part2(), 251786953);
    EXPECT_NE(d.Part2(), 251685203);
    EXPECT_NE(d.Part2(), 251512476);
}


