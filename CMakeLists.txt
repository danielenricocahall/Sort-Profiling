cmake_minimum_required(VERSION 3.21)
project(Sort_Profiling)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sort_Profiling
        BinarySearchTree.cpp
        BinarySearchTree.h
        BSTSorter.cpp
        BSTSorter.h
        BubbleSorter.cpp
        BubbleSorter.h
        Driver.cpp
        GnomeSorter.cpp
        GnomeSorter.h
        HeapSorter.cpp
        HeapSorter.h
        InsertionSorter.cpp
        InsertionSorter.h
        MergeSorter.cpp
        MergeSorter.h
        SelectionSorter.cpp
        SelectionSorter.h
        Sorter.cpp
        Sorter.h
        SorterFactory.cpp
        SorterFactory.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
