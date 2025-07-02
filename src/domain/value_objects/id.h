#pragma once

#include "value_object.h"
#include <cstdint>
#include <stdexcept>

class Id : public ValueObject<Id>
{
  public:
    explicit Id(int64_t value);

    int64_t value() const;

    operator int64_t() const;

    bool operator<(const Id &other) const;
    bool operator>(const Id &other) const;
    bool operator<=(const Id &other) const;
    bool operator>=(const Id &other) const;

  protected:
    bool equalsCore(const Id &other) const override;
    std::size_t getHashCodeCore() const override;

  private:
    int64_t value_;
};
