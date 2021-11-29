cmake_minimum_required(VERSION 3.20)
project(Lista4)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista4 main.cpp sources/Node/CNodeDynamic.cpp sources/Node/CNodeDynamic.h sources/Tree/CTreeDynamic.cpp sources/Tree/CTreeDynamic.h)
