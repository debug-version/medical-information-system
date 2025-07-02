#pragma once

#include "length_validator.h"
#include "value_object.h"
#include <stdexcept>
#include <string>

class StringBase : public ValueObject<StringBase>
{
  public:
    StringBase(const std::string &value, int minLen, int maxLen);

    virtual ~StringBase() = default;

    virtual const std::string &toString() const;
    virtual operator std::string() const;

  protected:
    std::string value_;

    bool equalsCore(const StringBase &other) const override;
    std::size_t getHashCodeCore() const override;
};
