#pragma once
#include "enum_base.h"
#include <boost/bimap.hpp>

enum class Gender { MALE, FEMALE };

class GenderEnum : public EnumBase<Gender>
{
  protected:
    const BimapType &getBimap() const override
    {
        static const BimapType genderBimap = [] {
            BimapType m;
            m.insert({"male", Gender::MALE});
            m.insert({"female", Gender::FEMALE});
            return m;
        }();
        return genderBimap;
    }
};
