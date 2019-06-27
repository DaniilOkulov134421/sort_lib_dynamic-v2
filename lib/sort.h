#pragma once

#include <vector>
#include <string>


extern "C" {
	__declspec(dllexport) void qsort_recursive(std::string& raw);
}

using _qsort_recursive = void(*)(std::string&);