#pragma once

#include "length_validator.h"
#include "space_validator.h"
#include "value_object.h"
#include <stdexcept>
#include <string>

class TextString : public ValueObject<TextString>
{
  public:
    TextString(const std::string &value, int minLen, int maxLen);
    explicit TextString(const std::string &value);

    const std::string &toString() const;

  protected:
    bool equalsCore(const TextString &other) const override;
    std::size_t getHashCodeCore() const override;

  private:
    void validateText(const std::string &value) const;

    std::string value_;
    LengthValidator lengthValidator_;
};
