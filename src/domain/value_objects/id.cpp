#include "id.h"
#include <functional>

Id::Id(int64_t value)
{
    if (value <= 0) {
        throw std::invalid_argument("ID must be greater than 0");
    }
    value_ = value;
}

int64_t Id::value() const
{
    return value_;
}

Id::operator int64_t() const
{
    return value_;
}

bool Id::operator<(const Id &other) const
{
    return value_ < other.value_;
}

bool Id::operator>(const Id &other) const
{
    return value_ > other.value_;
}

bool Id::operator<=(const Id &other) const
{
    return value_ <= other.value_;
}

bool Id::operator>=(const Id &other) const
{
    return value_ >= other.value_;
}

bool Id::equalsCore(const Id &other) const
{
    return value_ == other.value_;
}

std::size_t Id::getHashCodeCore() const
{
    return std::hash<int64_t>{}(value_);
}
