#pragma once

#include "space_validator.h"
#include "string_base.h"

class TextString : public StringBase
{
  public:
    explicit TextString(const std::string &value)
        : StringBase(value, 1, 128)
    {
        validateText(value_);
    }

  protected:
    TextString(const std::string &value, int minLen, int maxLen)
        : StringBase(value, minLen, maxLen)
    {
        validateText(value_);
    }

  private:
    static void validateText(const std::string &value)
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
};
