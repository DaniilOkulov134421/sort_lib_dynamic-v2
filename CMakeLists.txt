#Main project options
#------
cmake_minimum_required(VERSION 2.8)
	# Проверка версии CMake.
	# Если версия установленой программы
	# старее указаной, произайдёт аварийный выход.

project(file_sort)

string(APPEND CMAKE_C_FLAGS_DEBUG " -DDEBUG_FLAG")
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -DDEBUG_FLAG")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MTd")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_subdirectory(lib)

add_subdirectory(UTest)

add_subdirectory(googletest)

#В каждой папке свой CMake
