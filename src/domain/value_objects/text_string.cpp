#include "text_string.h"
#include <stdexcept>

TextString::TextString(const std::string &value)
    : StringBase(value, 1, 128)
{
    validateText(value_);
}

TextString::TextString(const std::string &value, int minLen, int maxLen)
    : StringBase(value, minLen, maxLen)
{
    validateText(value_);
}

void TextString::validateText(const std::string &value)
{
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
