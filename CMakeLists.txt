cmake_minimum_required(VERSION 3.24.2)

set(This cellarDoor)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE)

enable_testing()

find_package(jsoncpp REQUIRED)

add_subdirectory(googletest)

set(Headers
    ~/Projects/cellarDoor/src/character.h
    ~/Projects/cellarDoor/src/monster.h
    ~/Projects/cellarDoor/src/mobiles.h
    ~/Projects/cellarDoor/src/mobilesStats.h
    ~/Projects/cellarDoor/src/monstertype.h
    ~/Projects/cellarDoor/src/minion.h
    ~/Projects/cellarDoor/src/miniontype.h
    ~/Projects/cellarDoor/src/fromjson.h
)

set(Sources
    ~/Projects/cellarDoor/src/main.cc
    ~/Projects/cellarDoor/src/monster.cc
    ~/Projects/cellarDoor/src/character.cc
    ~/Projects/cellarDoor/src/minion.cc
)

add_library(${This} STATIC ${Sources} ${Headers})
target_link_libraries(${This} jsoncpp_lib)

add_subdirectory(test)