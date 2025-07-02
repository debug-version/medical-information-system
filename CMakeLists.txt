cmake_minimum_required(VERSION 3.30)

project(mis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(mis_executable_file ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_include_directories(
    mis_executable_file
    PRIVATE ${CMAKE_BINARY_DIR}
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/src/domain/entities
            ${CMAKE_SOURCE_DIR}/src/domain/value_objects
            ${CMAKE_SOURCE_DIR}/src/shared_kernel
            ${CMAKE_SOURCE_DIR}/src/utils/validators
)

add_subdirectory(tests)
