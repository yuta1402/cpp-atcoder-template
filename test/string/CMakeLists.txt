cmake_minimum_required(VERSION 3.1)

set(target string_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME string
    COMMAND $<TARGET_FILE:${target}>
)
