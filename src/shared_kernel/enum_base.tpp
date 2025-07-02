#pragma once

#include "enum_base.h"
#include <algorithm>
#include <cctype>
#include <ranges>
#include <stdexcept>
#include <string>

template <typename EnumType>
EnumType EnumBase<EnumType>::parseEnum(const std::string &value) const
{
    const auto &bimap = getBimap();
    std::string lowerValue = toLower(value);
    auto it = bimap.left.find(lowerValue);
    if (it != bimap.left.end())
        return it->second;
    throw std::invalid_argument("Invalid enum value: " + value);
}

template <typename EnumType>
std::string EnumBase<EnumType>::toString(EnumType enumValue) const
{
    const auto &bimap = getBimap();
    auto it = bimap.right.find(enumValue);
    if (it != bimap.right.end())
        return it->second;
    throw std::invalid_argument("Unknown enum value");
}

template <typename EnumType>
std::string EnumBase<EnumType>::toLower(const std::string &s)
{
    std::string result(s.size(), '\0');
    std::ranges::transform(s, result.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return result;
}
