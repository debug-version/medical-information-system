#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>
#include <stdexcept>
#include <string>

class Date
{
  public:
    using DateType = boost::gregorian::date;

    explicit Date(const DateType &date)
    {
        if (date < DateType(1900, 1, 1)) {
            throw std::invalid_argument(
                "Date must not be earlier than 1900-01-01"
            );
        }
        date_ = date;
    }

    explicit Date(const std::string &date)
        : Date(Date::fromISOFormat(date))
    {
    }

    static Date today()
    {
        return Date(boost::gregorian::day_clock::local_day());
    }

    static Date fromISOFormat(const std::string &str)
    {
        try {
            DateType date = boost::gregorian::date_from_iso_string(str);
            return Date(date);
        } catch (const std::exception &) {
            throw std::invalid_argument("Invalid date string format");
        }
    }

    int yearsSince(const Date &other) const
    {
        int years = date_.year() - other.date_.year();
        if (date_.month() < other.date_.month()
            || (date_.month() == other.date_.month()
                && date_.day() < other.date_.day())) {
            years -= 1;
        }
        return years;
    }

    std::string toISOFormat() const
    {
        return boost::gregorian::to_iso_string(date_);
    }

    operator DateType() const
    {
        return date_;
    }

    operator std::string() const
    {
        return toISOFormat();
    }

    bool operator==(const Date &other) const
    {
        return date_ == other.date_;
    }

    bool operator!=(const Date &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Date &other) const
    {
        return date_ < other.date_;
    }

    bool operator>(const Date &other) const
    {
        return date_ > other.date_;
    }

    bool operator<=(const Date &other) const
    {
        return date_ <= other.date_;
    }

    bool operator>=(const Date &other) const
    {
        return date_ >= other.date_;
    }

    int operator-(const Date &other) const
    {
        return (date_ - other.date_).days();
    }

  private:
    DateType date_;
};
