#include <gtest/gtest.h>
#include "nod.h"

TEST(NODTests, BasicCases) {
    EXPECT_EQ(calculateNOD(12, 18), 6);
    EXPECT_EQ(calculateNOD(18, 12), 6);  
    EXPECT_EQ(calculateNOD(7, 5), 1);  
}

TEST(NODTests, EqualNumbers) {
    EXPECT_EQ(calculateNOD(15, 15), 15);
    EXPECT_EQ(calculateNOD(1, 1), 1);
    EXPECT_EQ(calculateNOD(100, 100), 100);
}

TEST(NODTests, OneIsMultipleOfAnother) {
    EXPECT_EQ(calculateNOD(5, 15), 5);
    EXPECT_EQ(calculateNOD(15, 5), 5);
    EXPECT_EQ(calculateNOD(4, 16), 4);
}

TEST(NODTests, PrimeNumbers) {
    EXPECT_EQ(calculateNOD(13, 17), 1);
    EXPECT_EQ(calculateNOD(29, 31), 1);
}

TEST(NODTests, LargeNumbers) {
    EXPECT_EQ(calculateNOD(54, 24), 6);
    EXPECT_EQ(calculateNOD(48, 180), 12);
    EXPECT_EQ(calculateNOD(101, 103), 1); 
}

TEST(NODTests, WithZero) {
    EXPECT_EQ(calculateNOD(0, 5), 5);
    EXPECT_EQ(calculateNOD(5, 0), 5);
    EXPECT_EQ(calculateNOD(0, 0), 0); 
}

TEST(NODTests, NegativeNumbers) {

    EXPECT_EQ(calculateNOD(-12, 18), 6);
    EXPECT_EQ(calculateNOD(12, -18), 6);
    EXPECT_EQ(calculateNOD(-12, -18), 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}