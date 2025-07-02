#include "oms_policy_number.h"
#include <gtest/gtest.h>

TEST(OmsPolicyNumberTest, ValidNumbers)
{
    // Valid OMS policy number: exactly 16 digits
    EXPECT_NO_THROW(OmsPolicyNumber("1234567890123456"));
    EXPECT_NO_THROW(OmsPolicyNumber("6543210987654321"));
}

TEST(OmsPolicyNumberTest, InvalidFormat)
{
    // Too short
    EXPECT_THROW(OmsPolicyNumber("123456789012345"), std::invalid_argument);
    // Too long
    EXPECT_THROW(OmsPolicyNumber("12345678901234567"), std::invalid_argument);
    // Contains letters
    EXPECT_THROW(OmsPolicyNumber("12345678901234AB"), std::invalid_argument);
    // Contains spaces
    EXPECT_THROW(OmsPolicyNumber("1234 567890123456"), std::invalid_argument);
    // Empty string
    EXPECT_THROW(OmsPolicyNumber(""), std::invalid_argument);
}

TEST(OmsPolicyNumberTest, Equality)
{
    OmsPolicyNumber a("1234567890123456");
    OmsPolicyNumber b("1234567890123456");
    OmsPolicyNumber c("1111222233334444");
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_TRUE(a != c);
}
