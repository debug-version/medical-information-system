#include "person.h"
#include <gtest/gtest.h>
#include <optional>
#include <string>

TEST(PersonTest, CreateValidPerson_WithPatronymic)
{
    Person p(
        Id(1),
        WordString("Иванов"),
        WordString("Иван"),
        WordString("Иванович"),
        Date("20000101"),
        Gender::MALE,
        TextString("Москва, улица Мира, дом 1, квартира 1")
    );
    EXPECT_EQ(p.getId(), Id(1));
    EXPECT_EQ(p.getSurname(), WordString("Иванов"));
    EXPECT_EQ(p.getName(), WordString("Иван"));
    ASSERT_TRUE(p.getPatronymic().has_value());
    EXPECT_EQ(p.getPatronymic().value(), WordString("Иванович"));
    EXPECT_EQ(p.getBirthDate(), Date("20000101"));
    EXPECT_EQ(
        p.getAddress(), TextString("Москва, улица Мира, дом 1, квартира 1")
    );
    EXPECT_EQ(p.getGender(), Gender::MALE);
}

TEST(PersonTest, CreateValidPerson_EmptyPatronymic)
{
    Person p(
        Id(2),
        WordString("Петрова"),
        WordString("Анна"),
        Date("19901231"),
        Gender::FEMALE,
        TextString("Казань, улица Победы, дом 5, квартира 7")
    );
    EXPECT_FALSE(p.getPatronymic().has_value());
    EXPECT_EQ(p.getSurname(), WordString("Петрова"));
    EXPECT_EQ(p.getName(), WordString("Анна"));
    EXPECT_EQ(p.getGender(), Gender::FEMALE);
}

TEST(PersonTest, CreateValidPerson_Latin_AndMinMaxLength)
{
    std::string maxWord(64, 'a');
    std::string maxText(128, 'b');
    Person p(
        Id(3),
        WordString(maxWord),
        WordString("B"),
        WordString("C"),
        Date("20011212"),
        Gender::MALE,
        TextString(maxText)
    );
    EXPECT_EQ(p.getSurname(), WordString(maxWord));
    EXPECT_EQ(p.getAddress(), TextString(maxText));
}

TEST(PersonTest, CreateValidPerson_ShortestFields)
{
    Person p(
        Id(4),
        WordString("A"),
        WordString("B"),
        Date("20100101"),
        Gender::FEMALE,
        TextString("Z")
    );
    EXPECT_EQ(p.getSurname(), WordString("A"));
    EXPECT_EQ(p.getAddress(), TextString("Z"));
}

TEST(PersonTest, Mutability_SettersWorkCorrectly)
{
    // Create a person with initial values
    Person p(
        Id(10),
        WordString("Старова"),
        WordString("Светлана"),
        Date("19890520"),
        Gender::FEMALE,
        TextString("Санкт-Петербург, Ленина, дом 5")
    );

    // Change surname, name, patronymic, birth date, gender, address
    p.setSurname(WordString("Новикова"));      // Changing surname
    p.setName(WordString("Марина"));           // Changing name
    p.setPatronymic(WordString("Викторовна")); // Adding patronymic
    p.setBirthDate(Date("19950505"));          // Changing birth date
    p.setGender(Gender::MALE);                 // Changing gender
    p.setAddress(TextString("Екатеринбург, Победы, дом 9")); // Changing address

    // Check that all changes were applied
    EXPECT_EQ(p.getSurname(), WordString("Новикова"));
    EXPECT_EQ(p.getName(), WordString("Марина"));
    ASSERT_TRUE(p.getPatronymic().has_value());
    EXPECT_EQ(p.getPatronymic().value(), WordString("Викторовна"));
    EXPECT_EQ(p.getBirthDate(), Date("19950505"));
    EXPECT_EQ(p.getGender(), Gender::MALE);
    EXPECT_EQ(p.getAddress(), TextString("Екатеринбург, Победы, дом 9"));

    // Reset patronymic and check
    p.resetPatronymic(); // Remove patronymic
    EXPECT_FALSE(p.getPatronymic().has_value());
}

TEST(PersonTest, ThrowsOnInvalidId)
{
    // Should throw because id is <= 0
    EXPECT_THROW(
        Person(
            Id(0), // Invalid ID
            WordString("Иванов"),
            WordString("Иван"),
            Date("20010101"),
            Gender::MALE,
            TextString("Москва")
        ),
        std::invalid_argument
    );
}

TEST(PersonTest, ThrowsOnEmptySurname)
{
    // Should throw because surname is empty
    EXPECT_THROW(
        Person(
            Id(1),
            WordString(""), // Empty surname
            WordString("Иван"),
            Date("20010101"),
            Gender::MALE,
            TextString("Москва")
        ),
        std::invalid_argument
    );
}

TEST(PersonTest, ThrowsOnTooLongName)
{
    // Should throw because name is too long (65 characters)
    std::string tooLongName(65, 'A');
    EXPECT_THROW(
        Person(
            Id(2),
            WordString("Иванов"),
            WordString(tooLongName), // Too long name
            Date("20010101"),
            Gender::MALE,
            TextString("Москва")
        ),
        std::invalid_argument
    );
}

TEST(PersonTest, ThrowsOnEmptyAddress)
{
    // Should throw because address is empty
    EXPECT_THROW(
        Person(
            Id(3),
            WordString("Иванов"),
            WordString("Иван"),
            Date("20010101"),
            Gender::MALE,
            TextString("") // Empty address
        ),
        std::invalid_argument
    );
}

TEST(PersonTest, ThrowsOnTooLongAddress)
{
    // Should throw because address is too long (129 characters)
    std::string tooLongAddress(129, 'B');
    EXPECT_THROW(
        Person(
            Id(4),
            WordString("Иванов"),
            WordString("Иван"),
            Date("20010101"),
            Gender::MALE,
            TextString(tooLongAddress) // Too long address
        ),
        std::invalid_argument
    );
}

TEST(PersonTest, ThrowsOnInvalidDate)
{
    // Should throw because date is before 1900
    EXPECT_THROW(
        Person(
            Id(5),
            WordString("Иванов"),
            WordString("Иван"),
            Date("18991231"), // Invalid date
            Gender::MALE,
            TextString("Москва")
        ),
        std::invalid_argument
    );
}
