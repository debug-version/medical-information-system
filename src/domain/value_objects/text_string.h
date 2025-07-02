#pragma once

#include "space_validator.h"
#include "string_base.h"

class TextString : public StringBase
{
  public:
    explicit TextString(const std::string &value);

  protected:
    TextString(const std::string &value, int minLen, int maxLen);

  private:
    static void validateText(const std::string &value);
};
