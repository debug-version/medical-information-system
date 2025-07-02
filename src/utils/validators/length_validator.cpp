#include "length_validator.h"

#include <stdexcept>

LengthValidator::LengthValidator(int minLen, int maxLen)
    : minLen_(minLen)
    , maxLen_(maxLen)
{
    if (minLen < 0) {
        throw std::invalid_argument("minimum length must not be negative");
    }
    if (maxLen <= 0) {
        throw std::invalid_argument("maximum length must be positive");
    }
    if (minLen > maxLen) {
        throw std::invalid_argument(
            "minimum length must not exceed maximum length"
        );
    }
}

bool LengthValidator::checkLength(const std::string &str) const
{
    int len = static_cast<int>(str.length());
    return len >= minLen_ && len <= maxLen_;
}
