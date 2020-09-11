cmake_minimum_required(VERSION 3.10)
project(Laboratorio_)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(test)

set(SOURCE_FILES FileIni.cpp FileIni.h Print.cpp Print.h)
add_executable(Laboratorio_ main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Laboratorio_ core)
