cmake_minimum_required(VERSION 3.15)

set(GLOB_HEADERS
    src/macros.h
)

set(GLOB_SOURCES
)

set(GLOBS ${GLOB_HEADERS} ${GLOB_SOURCES})

project(1-01)
add_executable(1-01 src/1-01/main.c ${GLOBS})

project(1-01-alt)
add_executable(1-01-alt src/1-01/alternative.c ${GLOBS})

project(1-02)
add_executable(1-02 src/1-02/main.c ${GLOBS})

project(2-04)
add_executable(2-04 src/2-04/main.c ${GLOBS})

project(4-01)
add_executable(4-01 src/4-01/main.c ${GLOBS})

project(4-02)
add_executable(4-02 src/4-02/main.c ${GLOBS})

project(4-03)
add_executable(4-03 src/4-03/main.c ${GLOBS})
