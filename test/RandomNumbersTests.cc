#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../src/randomnumbers.h"

TEST(RandomNumbersTests, RandomNumberReturns10) {
  EXPECT_EQ(RandomNumbers::GetInstance()->Roll(10, 10), 10);
}

TEST(RandomNumbersTests, RandomNumberReturnsRandomBetween1and100) {
  int a = RandomNumbers::GetInstance()->Roll(1, 100);
  EXPECT_TRUE((a >= 1) && (a <= 100));
}