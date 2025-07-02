#pragma once

#include "value_object.h"

template <typename T> bool ValueObject<T>::operator==(const T &other) const
{
    return equalsCore(other);
}

template <typename T> bool ValueObject<T>::operator!=(const T &other) const
{
    return !(*this == other);
}

template <typename T>
bool ValueObject<T>::operator==(const ValueObject<T> &other) const
{
    auto ptr = dynamic_cast<const T *>(&other);
    if (ptr == nullptr)
        return false;
    return equalsCore(*ptr);
}

template <typename T>
bool ValueObject<T>::operator!=(const ValueObject<T> &other) const
{
    return !(*this == other);
}

template <typename T> std::size_t ValueObject<T>::hash() const
{
    return getHashCodeCore();
}
