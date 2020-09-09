cmake_minimum_required(VERSION 3.10)
project(Laboratorio_)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(/home/mirko25/CLionProjects/Laboratorio_/test/lib/googletest)
set(gtest_SOURCE_DIR, /home/mirko25/CLionProjects/Laboratorio_/test/lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES test.cpp)
add_executable(test runAllTest.cpp ${SOURCE_FILES} test.cpp)
target_link_libraries(test gtest gtest_main core)
