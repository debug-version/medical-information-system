#pragma once

#include <memory>
#include <type_traits>

template <typename T> class ValueObject
{
  public:
    virtual ~ValueObject() = default;

    bool operator==(const T &other) const
    {
        return equalsCore(other);
    }

    bool operator!=(const T &other) const
    {
        return !(*this == other);
    }

    // For pointer-based comparison through ValueObject<T>*
    bool operator==(const ValueObject<T> &other) const
    {
        // RTTI check in case comparing through the base type
        auto ptr = dynamic_cast<const T *>(&other);
        if (ptr == nullptr)
            return false;
        return equalsCore(*ptr);
    }

    bool operator!=(const ValueObject<T> &other) const
    {
        return !(*this == other);
    }

  protected:
    // Implement in derived classes for value comparison
    virtual bool equalsCore(const T &other) const = 0;
    // Implement in derived classes for hash calculation
    virtual std::size_t getHashCodeCore() const = 0;

  public:
    std::size_t hash() const
    {
        return getHashCodeCore();
    }
};
