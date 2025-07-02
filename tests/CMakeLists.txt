enable_testing()

add_executable(
    tests_executable_file
    ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/entities/person_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/validators/length_validator_test.cpp
    ${CMAKE_SOURCE_DIR}/src/domain/entities/person.cpp
    ${CMAKE_SOURCE_DIR}/src/shared_kernel/entity.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/validators/length_validator.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/validators/space_validator.cpp
)

find_package(GTest REQUIRED)
target_link_libraries(tests_executable_file PRIVATE gtest::gtest)

find_package(Boost REQUIRED COMPONENTS date_time)
target_link_libraries(tests_executable_file PRIVATE Boost::date_time)

target_include_directories(
    tests_executable_file
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/src/domain/entities
            ${CMAKE_SOURCE_DIR}/src/domain/value_objects
            ${CMAKE_SOURCE_DIR}/src/shared_kernel
            ${CMAKE_SOURCE_DIR}/src/utils/validators
)

add_test(NAME AllTests COMMAND tests_executable_file)
