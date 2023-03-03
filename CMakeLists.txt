cmake_minimum_required(VERSION 3.24.2)

set(This cellarDoor)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE)

enable_testing()

add_subdirectory(googletest)

set(Headers
    ~/Projects/cellarDoor/src/character.h
)

set(Sources
    ~/Projects/cellarDoor/src/main.cc
    ~/Projects/cellarDoor/src/character.cc
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)