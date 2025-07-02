#include "length_validator.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

TEST(LengthValidatorTest, CheckLength_Valid)
{
    LengthValidator validator(1, 4);

    EXPECT_TRUE(validator.checkLength("a"));
    EXPECT_TRUE(validator.checkLength("ab"));
    EXPECT_TRUE(validator.checkLength("abcd"));
    EXPECT_FALSE(validator.checkLength(""));
    EXPECT_FALSE(validator.checkLength("abcde"));
}

TEST(LengthValidatorTest, CheckLength_EmptyString)
{
    LengthValidator validator(0, 4);
    EXPECT_TRUE(validator.checkLength(""));
    EXPECT_TRUE(validator.checkLength("a"));
    EXPECT_TRUE(validator.checkLength("abcd"));
    EXPECT_FALSE(validator.checkLength("abcde"));
}

TEST(LengthValidatorTest, ThrowsOnInvalidMinMax)
{
    // minLen < 0
    EXPECT_THROW(LengthValidator(-1, 5), std::invalid_argument);

    // maxLen <= 0
    EXPECT_THROW(LengthValidator(0, 0), std::invalid_argument);
    EXPECT_THROW(LengthValidator(0, -1), std::invalid_argument);

    // minLen > maxLen
    EXPECT_THROW(LengthValidator(5, 2), std::invalid_argument);
}

TEST(LengthValidatorTest, EdgeCases)
{
    LengthValidator validator(2, 2);
    EXPECT_TRUE(validator.checkLength("ab"));
    EXPECT_FALSE(validator.checkLength(""));
    EXPECT_FALSE(validator.checkLength("a"));
    EXPECT_FALSE(validator.checkLength("abc"));
}
