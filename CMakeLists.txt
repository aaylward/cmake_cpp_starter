cmake_minimum_required(VERSION 3.20)

project(cpp_starter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

find_package(Boost 1.78 COMPONENTS program_options REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(cpp_starter ${SOURCES})

enable_testing()
add_executable(cpp_starter_test test/cpp_starter_test.cpp)
target_link_libraries(cpp_starter_test Boost::program_options gtest_main)

add_compile_options(-Wall -Wextra -Werror -fsanitize=address)
add_link_options(-fsanitize=address)

target_link_libraries(cpp_starter Boost::program_options)

include(GoogleTest)
gtest_discover_tests(cpp_starter_test)
