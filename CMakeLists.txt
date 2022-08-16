cmake_minimum_required(VERSION 3.21)
project(10Sorts)

set(CMAKE_CXX_STANDARD 14)

add_executable(10Sorts src/main.cpp src/BubbleSorts.cpp src/Sorts.h src/SelectionSort.cpp src/InsertionSort.cpp src/ShellSort.cpp src/MergeSort.cpp src/QuickSort.cpp src/HeapSort.cpp src/CountSort.cpp src/BucketSort.cpp src/RadixSort.cpp)
