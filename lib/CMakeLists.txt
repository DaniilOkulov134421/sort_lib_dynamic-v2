cmake_minimum_required(VERSION 2.8)
project(file_sort)

set(source_libs sort.cpp)
set(source_headers sort.h)

add_library(sort SHARED ${source_libs} ${source_headers})