#include "phone_number.h"
#include <gtest/gtest.h>

TEST(PhoneNumberTest, ValidNumbers)
{
    EXPECT_NO_THROW(PhoneNumber("71234567890"));
    EXPECT_NO_THROW(PhoneNumber("+71234567890"));
    EXPECT_NO_THROW(PhoneNumber("81234567890"));
}

TEST(PhoneNumberTest, InvalidFormat)
{
    // Too short
    EXPECT_THROW(PhoneNumber("+7123456789"), std::invalid_argument);
    // Too long
    EXPECT_THROW(PhoneNumber("+712345678901"), std::invalid_argument);
    // Invalid prefix
    EXPECT_THROW(PhoneNumber("+61234567890"), std::invalid_argument);
    // Contains letters
    EXPECT_THROW(PhoneNumber("+7abcdefghij"), std::invalid_argument);
    // Spaces in number
    EXPECT_THROW(PhoneNumber("+7 1234567890"), std::invalid_argument);
    // Dashes in number
    EXPECT_THROW(PhoneNumber("+7-123-456-7890"), std::invalid_argument);
    // Empty string
    EXPECT_THROW(PhoneNumber(""), std::invalid_argument);
}

TEST(PhoneNumberTest, Equality)
{
    PhoneNumber a("+71234567890");
    PhoneNumber b("+71234567890");
    PhoneNumber c("81234567890");
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_TRUE(a != c);
}
