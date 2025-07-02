#include "space_validator.h"
#include <algorithm>
#include <cctype>

bool SpaceValidator::noSpace(const std::string &str)
{
    return !std::ranges::any_of(str, [](char c) {
        return std::isspace(static_cast<unsigned char>(c));
    });
}

bool SpaceValidator::noDoubleSpace(const std::string &str)
{
    int space_count = 0;

    return std::ranges::find_if(
               str,
               [&space_count](char c) mutable {
                   bool is_space = std::isspace(static_cast<unsigned char>(c));
                   space_count = is_space ? space_count + 1 : 0;
                   return space_count > 1;
               }
           )
           == str.end();
}

bool SpaceValidator::noSpaceStartEnd(const std::string &str)
{
    if (str.empty()) {
        return true;
    }
    return !std::isspace(static_cast<unsigned char>(str.front()))
           && !std::isspace(static_cast<unsigned char>(str.back()));
}
