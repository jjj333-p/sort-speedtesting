cmake_minimum_required(VERSION 3.30)
project(program6)

set(CMAKE_CXX_STANDARD 17)

add_executable(program6 main.cpp
        quicksort9.11.h
        quicksort_random_pivot.h
        quicksort_median_pivot.h
        shellsort_variants.h
)
