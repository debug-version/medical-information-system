#pragma once

#include <stdexcept>

class Id
{
  public:
    explicit Id(int64_t value)
    {
        if (value <= 0) {
            throw std::invalid_argument("ID must be greater than 0");
        }
        value_ = value;
    }

    int64_t value() const
    {
        return value_;
    }

    operator int64_t() const
    {
        return value_;
    }

    bool operator==(const Id &other) const
    {
        return value_ == other.value_;
    }

    bool operator!=(const Id &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Id &other) const
    {
        return value_ < other.value_;
    }

    bool operator>(const Id &other) const
    {
        return value_ > other.value_;
    }

    bool operator<=(const Id &other) const
    {
        return value_ <= other.value_;
    }

    bool operator>=(const Id &other) const
    {
        return value_ >= other.value_;
    }

  private:
    int64_t value_;
};
