cmake_minimum_required(VERSION 3.24.2)

set(This cellarDoorTests)

set(Sources
    ExampleTests.cc
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC 
    gtest_main
    cellarDoor
)

add_test(
    NAME ${This}
    COMMAND ${This}
)