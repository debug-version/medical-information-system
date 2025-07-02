#pragma once

#include "date.h"
#include "entity.h"
#include "gender_enum.h"
#include "id.h"
#include "text_string.h"
#include "word_string.h"
#include <optional>

class Person : public Entity
{
  public:
    Person(
        Id id,
        const WordString &surname,
        const WordString &name,
        const Date &birthDate,
        Gender gender,
        const TextString &address
    );

    Person(
        Id id,
        const WordString &surname,
        const WordString &name,
        const WordString &patronymic,
        const Date &birthDate,
        Gender gender,
        const TextString &address
    );

    const WordString &getSurname() const;
    void setSurname(const WordString &surname);

    const WordString &getName() const;
    void setName(const WordString &name);

    const std::optional<WordString> &getPatronymic() const;
    void setPatronymic(const std::optional<WordString> &patronymic);
    void setPatronymic(const WordString &patronymic); // overload
    void resetPatronymic();

    const Date &getBirthDate() const;
    void setBirthDate(const Date &birthDate);

    Gender getGender() const;
    void setGender(Gender gender);

    const TextString &getAddress() const;
    void setAddress(const TextString &address);

    bool hasPatronymic() const;

    TextString getFullName() const;
    int getAgeInDays() const;
    int getAgeInYears() const;

  private:
    WordString surname_;
    WordString name_;
    std::optional<WordString> patronymic_;
    Date birthDate_;
    Gender gender_;
    TextString address_;
};
