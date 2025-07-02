#include "word_string.h"
#include <functional>

WordString::WordString(const std::string &value, int minLen, int maxLen)
    : value_(value)
    , lengthValidator_(minLen, maxLen)
{
    validateWord(value_);
}

WordString::WordString(const std::string &value)
    : WordString(value, 1, 64)
{
}

const std::string &WordString::toString() const
{
    return value_;
}

bool WordString::equalsCore(const WordString &other) const
{
    return value_ == other.value_;
}

std::size_t WordString::getHashCodeCore() const
{
    return std::hash<std::string>{}(value_);
}

void WordString::validateWord(const std::string &value) const
{
    if (!lengthValidator_.checkLength(value)) {
        throw std::invalid_argument(
            "WordString length is out of allowed range"
        );
    }
    if (!SpaceValidator::noSpace(value)) {
        throw std::invalid_argument("WordString must not contain spaces");
    }
}
