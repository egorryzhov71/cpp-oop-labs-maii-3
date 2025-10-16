#include <gtest/gtest.h>
#include "/workspaces/C++/include/fivee.h"

TEST(FiveTest, DefaultConstructor) {
    Five num;
    EXPECT_EQ(num.tostring(), "0");
}

TEST(FiveTest, StringConstructor) {
    Five num1("123");
    EXPECT_EQ(num1.tostring(), "123");
    
    Five num2("0000123");
    EXPECT_EQ(num2.tostring(), "123");
    
    Five num3("0");
    EXPECT_EQ(num3.tostring(), "0");
}

TEST(FiveTest, InvalidDigitThrows) {
    EXPECT_THROW(Five num("12345"), std::invalid_argument);
    EXPECT_THROW(Five num("12a34"), std::invalid_argument);
}

TEST(FiveTest, Plus) {
    Five num1("12");
    Five num2("3");
    Five result = num1.plus(num2);
    EXPECT_EQ(result.tostring(), "20");
}

TEST(FiveTest, PlusWithCarry) {
    Five num1("44");
    Five num2("1");
    Five result = num1.plus(num2);
    EXPECT_EQ(result.tostring(), "100");
}

TEST(FiveTest, Minus) {
    Five num1("20");
    Five num2("3");
    Five result = num1.minus(num2);
    EXPECT_EQ(result.tostring(), "12");
}

TEST(FiveTest, MinusWhenImpossible) {
    Five num1("3");
    Five num2("20");
    EXPECT_THROW(num1.minus(num2), std::underflow_error);
}

TEST(FiveTest, Equal) {
    Five num1("123");
    Five num2("123");
    Five num3("124");
    
    EXPECT_TRUE(num1.equal(num2));
    EXPECT_FALSE(num1.equal(num3));
}

TEST(FiveTest, Less) {
    Five num1("12");
    Five num2("20");
    
    EXPECT_TRUE(num1.less(num2));
    EXPECT_FALSE(num2.less(num1));
}

TEST(FiveTest, Greater) {
    Five num1("20");
    Five num2("12");
    
    EXPECT_TRUE(num1.greater(num2));
    EXPECT_FALSE(num2.greater(num1));
}
TEST(FiveTest, DifferentSizes) {
    Five num1("1000");
    Five num2("1");
    Five result = num1.plus(num2);
    EXPECT_EQ(result.tostring(), "1001");
}

TEST(FiveTest, Copy) {
    Five num1("123");
    Five num2 = num1.copy();
    
    EXPECT_TRUE(num1.equal(num2));
    EXPECT_NE(num1.getdata(), num2.getdata());
}

TEST(FiveTest, Immutability) {
    Five num1("123");
    Five num2("1");
    
    Five sum = num1.plus(num2);
    
    EXPECT_EQ(num1.tostring(), "123");
    EXPECT_EQ(num2.tostring(), "1");
    EXPECT_EQ(sum.tostring(), "124");
}