#pragma once

#include <memory>
#include <type_traits>

template <typename T> class ValueObject
{
  public:
    virtual ~ValueObject() = default;

    bool operator==(const T &other) const;
    bool operator!=(const T &other) const;
    bool operator==(const ValueObject<T> &other) const;
    bool operator!=(const ValueObject<T> &other) const;

  protected:
    // Implement in derived classes for value comparison
    virtual bool equalsCore(const T &other) const = 0;
    // Implement in derived classes for hash calculation
    virtual std::size_t getHashCodeCore() const = 0;

  public:
    std::size_t hash() const;
};

#include "value_object.tpp"
