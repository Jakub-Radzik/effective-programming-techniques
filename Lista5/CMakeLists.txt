cmake_minimum_required(VERSION 3.21)
project(Lista5)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lista5 main.cpp sources/CMySmartPointer.h sources/CRefCounter.h sources/CTable/CTable.cpp sources/CTable/CTable.h sources/CTab/CTab.cpp sources/CTab/CTab.h)
