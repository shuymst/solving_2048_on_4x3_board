cmake_minimum_required(VERSION 3.20.0)
project(solving_mid2048 CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3 -mtune=native -march=native -Wall -pedantic -DNDEBUG")

add_subdirectory(mid2048)
add_subdirectory(src)
add_subdirectory(test)