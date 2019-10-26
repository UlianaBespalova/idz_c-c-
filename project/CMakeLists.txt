cmake_minimum_required(VERSION 3.15)
project(project)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x -Wall -ggdb3")

set(LIB_SOURCE_FILES
        main.c
        data.c)

add_library(study_std_lib STATIC ${LIB_SOURCE_FILES})

add_executable(program main.c)
add_executable(tests_cppunit tests_cppunit.cpp)

target_link_libraries(program study_std_lib)
target_link_libraries(tests_cppunit study_std_lib)

include_directories(unit/cppunit/include)

find_library(CPPUNIT_LIB NAMES cppunit cppunitd PATHS /usr/local/lib)
set(CPPUNIT_LIBRARY ${CPPUNIT_LIB})
target_link_libraries(tests_cppunit ${CPPUNIT_LIBRARY})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(FindPkgConfig)
find_package(libnew REQUIRED)
include_directories(${LIBNEW_INCLUDE_DIR})
target_link_libraries(program ${LIBNEW_LIBRARY})

target_link_libraries(tests_cppunit ${LIBNEW_LIBRARY})