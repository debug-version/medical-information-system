#include "text_string.h"
#include <functional>

TextString::TextString(const std::string &value, int minLen, int maxLen)
    : value_(value)
    , lengthValidator_(minLen, maxLen)
{
    validateText(value_);
}

TextString::TextString(const std::string &value)
    : TextString(value, 1, 128)
{
}

const std::string &TextString::toString() const
{
    return value_;
}

bool TextString::equalsCore(const TextString &other) const
{
    return value_ == other.value_;
}

std::size_t TextString::getHashCodeCore() const
{
    return std::hash<std::string>{}(value_);
}

void TextString::validateText(const std::string &value) const
{
    if (!lengthValidator_.checkLength(value)) {
        throw std::invalid_argument(
            "TextString length is out of allowed range"
        );
    }
    if (!SpaceValidator::noDoubleSpace(value)) {
        throw std::invalid_argument(
            "TextString must not contain consecutive spaces"
        );
    }
    if (!SpaceValidator::noSpaceStartEnd(value)) {
        throw std::invalid_argument(
            "TextString must not start or end with a space"
        );
    }
}
