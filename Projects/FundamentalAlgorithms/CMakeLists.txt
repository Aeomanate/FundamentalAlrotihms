cmake_minimum_required(VERSION 3.27)
project(AlgorithmsLib)

set(PROJECT_SOURCES
        src/Algorithms.cpp
        include/FundamentalAlgorithms.h
        src/ExportDefinitions.h)

add_library(AlgorithmsLib ${PROJECT_SOURCES})
target_include_directories(AlgorithmsLib PUBLIC include)
