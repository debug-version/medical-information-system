#include "string_base.h"
#include <functional>

StringBase::StringBase(const std::string &value, int minLen, int maxLen)
    : value_(value)
{
    LengthValidator lenValidator(minLen, maxLen);
    if (!lenValidator.checkLength(value_)) {
        throw std::invalid_argument(
            "String length must be between " + std::to_string(minLen) + " and "
            + std::to_string(maxLen)
        );
    }
}

const std::string &StringBase::toString() const
{
    return value_;
}

StringBase::operator std::string() const
{
    return value_;
}

bool StringBase::equalsCore(const StringBase &other) const
{
    return value_ == other.value_;
}

std::size_t StringBase::getHashCodeCore() const
{
    return std::hash<std::string>{}(value_);
}
