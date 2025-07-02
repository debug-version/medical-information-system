#pragma once
#include <algorithm>
#include <boost/bimap.hpp>
#include <ranges>
#include <stdexcept>
#include <string>

template <typename EnumType> class EnumBase
{
  public:
    virtual ~EnumBase() = default;

    EnumType parseEnum(const std::string &value) const
    {
        const auto &bimap = getBimap();
        std::string lowerValue = toLower(value);
        auto it = bimap.left.find(lowerValue);
        if (it != bimap.left.end())
            return it->second;
        throw std::invalid_argument("Invalid enum value: " + value);
    }

    std::string toString(EnumType enumValue) const
    {
        const auto &bimap = getBimap();
        auto it = bimap.right.find(enumValue);
        if (it != bimap.right.end())
            return it->second;
        throw std::invalid_argument("Unknown enum value");
    }

  protected:
    using BimapType = boost::bimap<std::string, EnumType>;
    virtual const BimapType &getBimap() const = 0;

  private:
    static std::string toLower(const std::string &s)
    {
        std::string result(s.size(), '\0');
        std::ranges::transform(s, result.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        return result;
    }
};
