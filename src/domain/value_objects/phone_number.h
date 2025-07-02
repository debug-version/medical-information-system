#pragma once

#include "value_object.h"
#include <regex>
#include <stdexcept>
#include <string>

class PhoneNumber : public ValueObject<PhoneNumber>
{
  public:
    explicit PhoneNumber(const std::string &value);

    const std::string &toString() const;

  protected:
    bool equalsCore(const PhoneNumber &other) const override;
    std::size_t getHashCodeCore() const override;

  private:
    void validatePhone(const std::string &value) const;

    std::string value_;
};
