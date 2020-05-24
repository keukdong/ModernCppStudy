
#ifndef CPP11_HEADER /* include guard of cpp11 header file*/
#define CPP11_HEADER 

#include <iostream>
#include <vector>

#include <Windows.h>

void PrintLog(const TCHAR* LogText)
{
    std::cout << LogText << std::endl;
}

auto ScopedEnums() -> int;
auto ScopedEnumExamples() ->int;

#endif
