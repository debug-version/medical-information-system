#include "date.h"
#include <gtest/gtest.h>

// Test for correct date format (YYYYMMDD)
TEST(DateTest, FormatOnly)
{
    EXPECT_NO_THROW(Date("20000102"));

    EXPECT_THROW(Date("02-01-2000"), std::invalid_argument);
    EXPECT_THROW(Date("2000/01/02"), std::invalid_argument);
    EXPECT_THROW(Date("2000-1-02"), std::invalid_argument);
    EXPECT_THROW(Date("2000-01-2a"), std::invalid_argument);
    EXPECT_THROW(Date(""), std::invalid_argument);
    EXPECT_THROW(Date(" 2000-01-02"), std::invalid_argument);
    EXPECT_THROW(Date("2000-01-02 "), std::invalid_argument);
    EXPECT_THROW(Date(" 2000-01-02 "), std::invalid_argument);
}

// Test for date existence (valid and invalid dates)
TEST(DateTest, DateExistence)
{
    EXPECT_NO_THROW(Date("20240228"));
    EXPECT_NO_THROW(Date("20241231"));

    EXPECT_THROW(Date("20241315"), std::invalid_argument);
    EXPECT_THROW(Date("20240230"), std::invalid_argument);
    EXPECT_THROW(Date("20240431"), std::invalid_argument);
    EXPECT_THROW(Date("20240010"), std::invalid_argument);
    EXPECT_THROW(Date("20240100"), std::invalid_argument);
    EXPECT_THROW(Date("20240532"), std::invalid_argument);
}

// Test for leap year (valid and invalid dates)
TEST(DateTest, LeapYear)
{
    EXPECT_NO_THROW(Date("20240229"));
    EXPECT_NO_THROW(Date("20000229"));

    EXPECT_THROW(Date("20230229"), std::invalid_argument);
    EXPECT_THROW(Date("19000229"), std::invalid_argument);

    EXPECT_THROW(Date("18000101"), std::invalid_argument);
}

TEST(DateTest, EqualityOperator)
{
    Date date1("20250615");
    Date date2("20250615");
    Date date3("20250701");

    EXPECT_TRUE(date1 == date2);
    EXPECT_FALSE(date1 == date3);
}

TEST(DateTest, InequalityOperator)
{
    Date date1("20250615");
    Date date2("20250615");
    Date date3("20250701");

    EXPECT_FALSE(date1 != date2);
    EXPECT_TRUE(date1 != date3);
}

TEST(DateTest, LessThanOperator)
{
    Date date1("20250615");
    Date date2("20250701");

    EXPECT_TRUE(date1 < date2);
    EXPECT_FALSE(date2 < date1);
}

TEST(DateTest, GreaterThanOperator)
{
    Date date1("20250615");
    Date date2("20250701");

    EXPECT_FALSE(date1 > date2);
    EXPECT_TRUE(date2 > date1);
}

TEST(DateTest, LessThanOrEqualOperator)
{
    Date date1("20250615");
    Date date2("20250701");
    Date date3("20250615");

    EXPECT_TRUE(date1 <= date2);
    EXPECT_TRUE(date1 <= date3);
    EXPECT_FALSE(date2 <= date1);
}

TEST(DateTest, GreaterThanOrEqualOperator)
{
    Date date1("20250615");
    Date date2("20250701");
    Date date3("20250615");

    EXPECT_FALSE(date1 >= date2);
    EXPECT_TRUE(date1 >= date3);
    EXPECT_TRUE(date2 >= date1);
}

TEST(DateTest, ImplicitConversionToString)
{
    Date date("20250615");

    std::string dateStr = date;

    EXPECT_EQ(dateStr, "20250615");
}

TEST(DateTest, DateToStringConversion)
{
    Date date = Date::fromISOFormat("20250615");

    EXPECT_EQ(date.toISOFormat(), "20250615");
}

TEST(DateTest, YearsSince_SimpleCases)
{
    Date d1("20000101");
    Date d2("20150101");
    EXPECT_EQ(d2.yearsSince(d1), 15); // exactly 15 years passed

    Date d3("20151231");
    EXPECT_EQ(d3.yearsSince(d1), 15); // last day of the year, still 15
}

TEST(DateTest, YearsSince_BirthdayNotYet)
{
    Date birth("20000610");
    Date check("20240609");
    EXPECT_EQ(check.yearsSince(birth), 23); // birthday not reached yet in 2024
}

TEST(DateTest, YearsSince_BirthdayToday)
{
    Date birth("20000610");
    Date check("20240610");
    EXPECT_EQ(check.yearsSince(birth), 24); // birthday today, full year counted
}

TEST(DateTest, YearsSince_BirthdayPassed)
{
    Date birth("20000610");
    Date check("20240611");
    EXPECT_EQ(
        check.yearsSince(birth), 24
    ); // birthday already passed in this year
}

TEST(DateTest, YearsSince_DifferentMonth)
{
    Date birth("20000510");
    Date check("20240609");
    EXPECT_EQ(
        check.yearsSince(birth), 24
    ); // different month, full year counted
}

TEST(DateTest, YearsSince_SameDate)
{
    Date d("20181212");
    EXPECT_EQ(d.yearsSince(d), 0); // same date, zero years
}

TEST(DateTest, YearsSince_LeapYearBirthday)
{
    Date birth("20000229");
    Date check("20240301");
    EXPECT_EQ(check.yearsSince(birth), 24); // after leap day, full year counted

    Date check2("20240228");
    EXPECT_EQ(check2.yearsSince(birth), 23); // before leap day, not full year

    Date check3("20240229");
    EXPECT_EQ(
        check3.yearsSince(birth), 24
    ); // exactly on next leap day, full year counted
}
