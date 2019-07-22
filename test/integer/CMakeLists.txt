cmake_minimum_required(VERSION 3.1)

set(target integer_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME integer
    COMMAND $<TARGET_FILE:${target}>
)
