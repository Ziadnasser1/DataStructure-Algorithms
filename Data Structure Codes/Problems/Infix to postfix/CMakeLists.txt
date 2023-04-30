cmake_minimum_required(VERSION 3.24)
project(Infix_to_postfix)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}../../Data Structure Codes/Lists/StackLLBased)

add_executable(Infix_to_postfix main.cpp)
