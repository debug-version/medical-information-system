#include "phone_number.h"
#include <functional>

PhoneNumber::PhoneNumber(const std::string &value)
    : value_(value)
{
    validatePhone(value_);
}

const std::string &PhoneNumber::toString() const
{
    return value_;
}

bool PhoneNumber::equalsCore(const PhoneNumber &other) const
{
    return value_ == other.value_;
}

std::size_t PhoneNumber::getHashCodeCore() const
{
    return std::hash<std::string>{}(value_);
}

void PhoneNumber::validatePhone(const std::string &value) const
{
    // Example:
    // +71234567890
    // 71234567890
    // 81234567890
    static const std::regex phoneRegex(R"(^(\+?7|8)\d{10}$)");
    if (!std::regex_match(value, phoneRegex)) {
        throw std::invalid_argument("Invalid phone number format");
    }
}
