
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

auto Constexpr() -> int;
auto ConstexprExamples() -> int;

auto VariadicTemplate() -> int;

auto AutoDecltype() -> int;

auto RValueReference() -> int;
auto MoveConstructor() -> int;

auto Nullptr() -> int;

auto Attributes() -> int;

auto LambdaExpression() -> int;

auto RangedFor() -> int;

auto Staticassertion() -> int;

#endif
