#include "oms_policy_number.h"
#include <functional>

OmsPolicyNumber::OmsPolicyNumber(const std::string &value)
    : value_(value)
{
    validatePolicy(value_);
}

const std::string &OmsPolicyNumber::toString() const
{
    return value_;
}

bool OmsPolicyNumber::equalsCore(const OmsPolicyNumber &other) const
{
    return value_ == other.value_;
}

std::size_t OmsPolicyNumber::getHashCodeCore() const
{
    return std::hash<std::string>{}(value_);
}

void OmsPolicyNumber::validatePolicy(const std::string &value) const
{
    static const std::regex policyRegex(R"(^\d{16}$)");
    if (!std::regex_match(value, policyRegex)) {
        throw std::invalid_argument("Invalid OMS policy number format");
    }
}
