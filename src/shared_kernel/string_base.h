#pragma once

#include "length_validator.h"
#include <stdexcept>
#include <string>

class StringBase
{
  public:
    StringBase(const std::string &value, int minLen, int maxLen)
        : value_(value)
    {
        LengthValidator lenValidator(minLen, maxLen);
        if (!lenValidator.checkLength(value_)) {
            throw std::invalid_argument(
                "String length must be between " + std::to_string(minLen)
                + " and " + std::to_string(maxLen)
            );
        }
    }

    virtual ~StringBase() = default;

    virtual const std::string &toString() const
    {
        return value_;
    }
    virtual operator std::string() const
    {
        return value_;
    }

    virtual bool operator==(const StringBase &other) const
    {
        return value_ == other.value_;
    }
    virtual bool operator!=(const StringBase &other) const
    {
        return !(*this == other);
    }

  protected:
    std::string value_;
};
