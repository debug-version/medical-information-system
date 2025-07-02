#include "date.h"

Date::Date(const DateType &date)
{
    if (date < DateType(1900, 1, 1)) {
        throw std::invalid_argument("Date must not be earlier than 1900-01-01");
    }
    date_ = date;
}

Date::Date(const std::string &date)
    : Date(Date::fromISOFormat(date))
{
}

Date Date::today()
{
    return Date(boost::gregorian::day_clock::local_day());
}

Date Date::fromISOFormat(const std::string &str)
{
    try {
        DateType date = boost::gregorian::date_from_iso_string(str);
        return Date(date);
    } catch (const std::exception &) {
        throw std::invalid_argument("Invalid date string format");
    }
}

int Date::yearsSince(const Date &other) const
{
    int years = date_.year() - other.date_.year();
    if (date_.month() < other.date_.month()
        || (date_.month() == other.date_.month()
            && date_.day() < other.date_.day())) {
        years -= 1;
    }
    return years;
}

std::string Date::toISOFormat() const
{
    return boost::gregorian::to_iso_string(date_);
}

Date::operator DateType() const
{
    return date_;
}

Date::operator std::string() const
{
    return toISOFormat();
}

bool Date::operator<(const Date &other) const
{
    return date_ < other.date_;
}

bool Date::operator>(const Date &other) const
{
    return date_ > other.date_;
}

bool Date::operator<=(const Date &other) const
{
    return date_ <= other.date_;
}

bool Date::operator>=(const Date &other) const
{
    return date_ >= other.date_;
}

int Date::operator-(const Date &other) const
{
    return (date_ - other.date_).days();
}

bool Date::equalsCore(const Date &other) const
{
    return date_ == other.date_;
}

std::size_t Date::getHashCodeCore() const
{
    // Simple hash, can be improved
    return static_cast<std::size_t>(
        date_.year() * 10000 + date_.month() * 100 + date_.day()
    );
}
