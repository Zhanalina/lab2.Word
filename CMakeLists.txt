cmake_minimum_required(VERSION 3.10)
project(MatrixProgram)

set(CMAKE_CXX_STANDARD 20)

add_executable(MatrixProgram main2.cpp Func2.cpp Func1.cpp)

target_include_directories(MatrixProgram PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})