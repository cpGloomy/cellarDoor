cmake_minimum_required(VERSION 3.24.2)

set(This cellarDoorTests)

file(GLOB all_SRC
    "${PROJECT_SOURCE_DIR}/test/*.cc"  
)

add_executable(${This} ${all_SRC})

target_link_libraries(${This} PUBLIC 
    gtest_main
    cellarDoor
)

add_test(
    NAME ${This}
    COMMAND ${This}
)