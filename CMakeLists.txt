cmake_minimum_required(VERSION 3.24.2)

set(This cellarDoor)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE)

enable_testing()

# Boost
find_package(Boost 1.81.0 COMPONENTS system filesystem serialization REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})
message("boost lib: ${Boost_LIBRARIES}")
message("boost inc:${Boost_INCLUDE_DIR}")


find_package(jsoncpp REQUIRED)

add_subdirectory(googletest)
include_directories(${CMAKE_SOURCE_DIR}/data)

set(Headers
    ~/Projects/cellarDoor/src/character.h
    ~/Projects/cellarDoor/src/mobilestype.h
    ~/Projects/cellarDoor/src/monster.h
    ~/Projects/cellarDoor/src/mobiles.h
    ~/Projects/cellarDoor/src/mobilesstatsheet.h
    ~/Projects/cellarDoor/src/minion.h
    ~/Projects/cellarDoor/src/fromjson.h
    ~/Projects/cellarDoor/src/boostpractice.h
)

set(Sources
    ~/Projects/cellarDoor/src/main.cc
    ~/Projects/cellarDoor/src/monster.cc
    ~/Projects/cellarDoor/src/character.cc
    ~/Projects/cellarDoor/src/minion.cc
)

add_library(${This} STATIC ${Sources} ${Headers})
target_link_libraries(${This} jsoncpp_lib ${Boost_LIBRARIES})

add_subdirectory(test)