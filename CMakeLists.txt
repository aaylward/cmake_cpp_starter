cmake_minimum_required(VERSION 3.20)

project(cpp_starter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.78 COMPONENTS program_options REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_compile_options(-Wall -Wextra -Werror -Wshadow -pedantic)
add_executable(cpp_starter ${SOURCES})
target_link_libraries(cpp_starter Boost::program_options)
