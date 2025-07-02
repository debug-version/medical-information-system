#pragma once

#include "space_validator.h"
#include "string_base.h"
#include <stdexcept>
#include <string>

class WordString : public StringBase
{
  public:
    explicit WordString(const std::string &value);

    WordString(const std::string &value, int minLen, int maxLen);

  private:
    static void validateWord(const std::string &value);
};
