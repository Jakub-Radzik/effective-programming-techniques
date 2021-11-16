cmake_minimum_required(VERSION 3.20)
project(List3)

set(CMAKE_CXX_STANDARD 98)

add_executable(List3 main.cpp sources/CNodeStatic/CNodeStatic.cpp sources/CNodeStatic/CNodeStatic.h sources/CTreeStatic/CTreeStatic.cpp sources/CTreeStatic/CTreeStatic.h sources/CNodeDynamic/CNodeDynamic.cpp sources/CNodeDynamic/CNodeDynamic.h sources/CTreeDynamic/CTreeDynamic.cpp sources/CTreeDynamic/CTreeDynamic.h)
