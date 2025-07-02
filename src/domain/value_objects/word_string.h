#pragma once

#include "space_validator.h"
#include "string_base.h"

class WordString : public StringBase
{
  public:
    explicit WordString(const std::string &value)
        : StringBase(value, 1, 64)
    {
        validateWord(value_);
    }

    WordString(const std::string &value, int minLen, int maxLen)
        : StringBase(value, minLen, maxLen)
    {
        validateWord(value_);
    }

  private:
    static void validateWord(const std::string &value)
    {
        if (!SpaceValidator::noSpace(value)) {
            throw std::invalid_argument("WordString must not contain spaces");
        }
    }
};
