enable_testing()

add_executable(
    tests_executable_file
    ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/validators/length_validator_test.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/validators/length_validator.cpp
)

find_package(GTest REQUIRED)
target_link_libraries(tests_executable_file PRIVATE gtest::gtest)

target_include_directories(
    tests_executable_file
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/src/utils/validators
)

add_test(NAME AllTests COMMAND tests_executable_file)
