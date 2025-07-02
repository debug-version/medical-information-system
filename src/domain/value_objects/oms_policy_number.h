#pragma once

#include "value_object.h"
#include <regex>
#include <stdexcept>
#include <string>

class OmsPolicyNumber : public ValueObject<OmsPolicyNumber>
{
  public:
    explicit OmsPolicyNumber(const std::string &value);

    const std::string &toString() const;

  protected:
    bool equalsCore(const OmsPolicyNumber &other) const override;
    std::size_t getHashCodeCore() const override;

  private:
    void validatePolicy(const std::string &value) const;

    std::string value_;
};
