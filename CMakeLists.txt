cmake_minimum_required(VERSION 3.15)

set(GLOB_HEADERS
    src/macros.h
)

project(1-01)
add_executable(1-01 src/1-01/main.c ${GLOB_HEADERS})

project(1-02)
add_executable(1-02 src/1-02/main.c ${GLOB_HEADERS})

project(2-04)
add_executable(2-04 src/2-04/main.c ${GLOB_HEADERS})
