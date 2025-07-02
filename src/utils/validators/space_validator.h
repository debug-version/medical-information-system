#pragma once

#include <string>

class SpaceValidator
{
  public:
    static bool noSpace(const std::string &str);

    static bool noDoubleSpace(const std::string &str);

    static bool noSpaceStartEnd(const std::string &str);
};
