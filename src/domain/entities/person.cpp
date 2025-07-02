#include "person.h"
#include "text_string.h"

#include <string>

// Designer without patronymic
Person::Person(
    Id id,
    const WordString &surname,
    const WordString &name,
    const Date &birthDate,
    Gender gender,
    const TextString &address
)
    : Entity(id)
    , surname_(surname)
    , name_(name)
    , patronymic_(std::nullopt)
    , birthDate_(birthDate)
    , gender_(gender)
    , address_(address)
{
}

// Designer with patronymic
Person::Person(
    Id id,
    const WordString &surname,
    const WordString &name,
    const WordString &patronymic,
    const Date &birthDate,
    Gender gender,
    const TextString &address
)
    : Entity(id)
    , surname_(surname)
    , name_(name)
    , patronymic_(patronymic)
    , birthDate_(birthDate)
    , gender_(gender)
    , address_(address)
{
}

const WordString &Person::getSurname() const
{
    return surname_;
}

void Person::setSurname(const WordString &surname)
{
    surname_ = surname;
}

const WordString &Person::getName() const
{
    return name_;
}

void Person::setName(const WordString &name)
{
    name_ = name;
}

const std::optional<WordString> &Person::getPatronymic() const
{
    return patronymic_;
}

void Person::setPatronymic(const std::optional<WordString> &patronymic)
{
    patronymic_ = patronymic;
}

void Person::setPatronymic(const WordString &patronymic)
{
    patronymic_ = patronymic;
}

void Person::resetPatronymic()
{
    patronymic_.reset();
}

const Date &Person::getBirthDate() const
{
    return birthDate_;
}

void Person::setBirthDate(const Date &birthDate)
{
    birthDate_ = birthDate;
}

Gender Person::getGender() const
{
    return gender_;
}

void Person::setGender(Gender gender)
{
    gender_ = gender;
}

const TextString &Person::getAddress() const
{
    return address_;
}

void Person::setAddress(const TextString &address)
{
    address_ = address;
}

bool Person::hasPatronymic() const
{
    return patronymic_.has_value();
}

TextString Person::getFullName() const
{
    std::string fullName = surname_.toString() + " " + name_.toString();
    if (patronymic_) {
        fullName += " " + patronymic_->toString();
    }
    return TextString(fullName);
}

int Person::getAgeInDays() const
{
    return Date::today() - birthDate_;
}

int Person::getAgeInYears() const
{
    return Date::today().yearsSince(birthDate_);
}
