#pragma once

#include "length_validator.h"
#include "space_validator.h"
#include "value_object.h"
#include <stdexcept>
#include <string>

class WordString : public ValueObject<WordString>
{
  public:
    WordString(const std::string &value, int minLen, int maxLen);
    explicit WordString(const std::string &value);

    const std::string &toString() const;

  protected:
    bool equalsCore(const WordString &other) const override;
    std::size_t getHashCodeCore() const override;

  private:
    void validateWord(const std::string &value) const;

    std::string value_;
    LengthValidator lengthValidator_;
};
