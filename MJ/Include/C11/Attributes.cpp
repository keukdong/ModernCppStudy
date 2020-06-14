
#include "Cpp11.h"

using namespace std;


// https://wikidocs.net/51417
// Attribute: 컴파일러에게 여러가지 힌트를 줄 수있다.

[[namespace::Attribute]]


[[noreturn]] void NoReturnValueFunc()
{
    // 얼핏 보기에 컴파일러에게 어떤 값도 반환하지 않겠다는 것처럼 보이지만
    // 컴파일러에게 코드 control flow상 caller에게 다시 돌아가지 않는다는 것을 의미;
}

[[noreturn, deprecated("do not use anymore")]]  // 사용하면 warning에 deprecated 메시지를 띄운다.
void DeprecatedFunction()
{
    ;
}

// C++20 부터 likely, unlikely가 도입되었다.
// c++ 20 : https://en.cppreference.com/w/cpp/language/attributes/likely
// https://stackoverflow.com/questions/51797959/how-to-use-c20s-likely-unlikely-attribute-in-if-else-statement


auto Attributes() -> int
{

    NoReturnValueFunc();
    std::cout << "control flow back ?" << std::endl;

    int a = 10;

    switch (a)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 9:
        [[fallthrough]];    // case9에 왔을때 default로 들어가겠다.
    default:
        ;
    }

    int A = 5;
    int B = 6;

    if( A > B) [[likely]]   // c++20 feature
    {
        A = B;
    }

    return 0;
}