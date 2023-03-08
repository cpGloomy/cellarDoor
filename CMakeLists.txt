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

file(GLOB all_SRC
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.cc"  
)

add_library(${This} STATIC ${all_SRC})
target_link_libraries(${This} jsoncpp_lib ${Boost_LIBRARIES})

add_subdirectory(test)