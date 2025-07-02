#pragma once

#include "value_object.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <stdexcept>
#include <string>

class Date : public ValueObject<Date>
{
  public:
    using DateType = boost::gregorian::date;

    explicit Date(const DateType &date);
    explicit Date(const std::string &date);

    static Date today();
    static Date fromISOFormat(const std::string &str);

    int yearsSince(const Date &other) const;
    std::string toISOFormat() const;

    operator DateType() const;
    operator std::string() const;

    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;
    int operator-(const Date &other) const;

  protected:
    bool equalsCore(const Date &other) const override;
    std::size_t getHashCodeCore() const override;

  private:
    DateType date_;
};
