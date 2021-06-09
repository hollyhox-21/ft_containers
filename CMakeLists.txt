cmake_minimum_required(VERSION 3.17.5)
project(ft_containers)

#set(CMAKE_CXX_FLAGS  "-Wall -Wextra -Werror")
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(tests_stl tests_stl/lib)

add_executable(ft_containers main.cpp List.hpp Vector.hpp Map.hpp)