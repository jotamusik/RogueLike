cmake_minimum_required(VERSION 3.5)
project(RogueLike)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    amuleto.cpp
    amuleto.hpp
        main.cpp
    mazmorra.cpp
    mazmorra.hpp
    monstruo.cpp
    monstruo.hpp
    protagonista.cpp
    protagonista.hpp    tablero.cpp
    tablero.hpp)

add_executable(RogueLike ${SOURCE_FILES})