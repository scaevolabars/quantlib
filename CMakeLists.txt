cmake_minimum_required(VERSION 3.16)
project(quantlib)

set(CMAKE_CXX_STANDARD 17)

add_executable(quantlib main.cpp EuropeanOption.cpp)