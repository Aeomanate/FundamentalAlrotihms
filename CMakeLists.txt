cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/RuntimeOutput")

project(AlgorithmsOnQt)

enable_testing()

add_subdirectory(Projects/FundamentalAlgorithms)
add_subdirectory(Projects/AlgoTests)
add_subdirectory(Projects/QtGui)
