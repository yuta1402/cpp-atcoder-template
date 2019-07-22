cmake_minimum_required(VERSION 3.1)

set(target graph_test)

add_executable(${target}
    ./main.cpp
)

add_test(
    NAME graph
    COMMAND $<TARGET_FILE:${target}>
)
