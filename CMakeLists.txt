cmake_minimum_required(VERSION 3.15)

include(dependencies/lists/include.cmake)

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

project(1-02-alt)
add_executable(1-02-alt src/1-02/alternative.c ${GLOBS})
target_link_libraries(1-02-alt m)

project(2-04)
add_executable(2-04 src/2-04/main.c ${GLOBS})

project(4-01)
add_executable(4-01 src/4-01/main.c ${GLOBS})

project(4-02)
add_executable(4-02 src/4-02/main.c ${GLOBS})

project(4-03)
add_executable(4-03 src/4-03/main.c ${GLOBS})

project(6-01)
add_executable(6-01 src/6-01/main.c src/6-01/int_ll.h src/6-01/int_ll.c ${GLOBS})

project(8-01)
add_executable(8-01 src/8-01/main.c)
target_link_libraries(8-01 PUBLIC lists-c)
target_include_directories(8-01 PUBLIC ${LISTS_C_INCLUDE_DIR})

project(base)
add_executable(base src/base/main.c src/6-01/int_ll.h src/6-01/int_ll.c ${GLOBS})

project(recursive-length)
add_executable(recursive-length src/recursive-length/main.c)
target_link_libraries(recursive-length PUBLIC lists-c)
target_include_directories(recursive-length PUBLIC ${LISTS_C_INCLUDE_DIR})

project(11-01)
add_executable(11-01 src/11-01/main.c src/11-01/btree.c src/11-01/btree.h ${GLOBS})
