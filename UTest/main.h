#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>

#include "../googletest/googletest/include/gtest/gtest.h"
#include "../lib/sort.h"

using std::string; //��� ��� ���� ����� �� ����� ���� ������ std:: ����� string

// ������� ����� ��� ���������� �� ������� ��� �� ����������, ��� � �������, ������� �� ������ �� dll

typedef void (*DllFunc) (string & raw);