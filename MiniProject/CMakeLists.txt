cmake_minimum_required(VERSION 3.21)
project(MiniProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(MiniProject main.cpp Max3Sat/CMax3SatProblem.cpp Max3Sat/CMax3SatProblem.h Max3Sat/Node.cpp Max3Sat/Node.h Max3Sat/Sentence.cpp Max3Sat/Sentence.h CGAOptimizer/CGAOptimizer.h CGAOptimizer/CGAIndividual/CGAIndividual.cpp CGAOptimizer/CGAIndividual/CGAIndividual.h CGAOptimizer/CGAOptimizer.cpp)
