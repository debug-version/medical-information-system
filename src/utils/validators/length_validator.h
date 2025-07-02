#pragma once

#include <string>

class LengthValidator
{
  public:
    LengthValidator(int minLen, int maxLen);

    bool checkLength(const std::string &str) const;

  private:
    int minLen_;
    int maxLen_;
};
