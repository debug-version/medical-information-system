#include "word_string.h"

WordString::WordString(const std::string &value)
    : StringBase(value, 1, 64)
{
    validateWord(value_);
}

WordString::WordString(const std::string &value, int minLen, int maxLen)
    : StringBase(value, minLen, maxLen)
{
    validateWord(value_);
}

void WordString::validateWord(const std::string &value)
{
    if (!SpaceValidator::noSpace(value)) {
        throw std::invalid_argument("WordString must not contain spaces");
    }
}
