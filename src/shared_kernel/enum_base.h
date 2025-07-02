#pragma once

#include <boost/bimap.hpp>
#include <string>

template <typename EnumType> class EnumBase
{
  public:
    virtual ~EnumBase() = default;

    EnumType parseEnum(const std::string &value) const;
    std::string toString(EnumType enumValue) const;

  protected:
    using BimapType = boost::bimap<std::string, EnumType>;
    virtual const BimapType &getBimap() const = 0;

  private:
    static std::string toLower(const std::string &s);
};

#include "enum_base.tpp"
