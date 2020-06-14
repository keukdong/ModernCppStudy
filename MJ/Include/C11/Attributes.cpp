
#include "Cpp11.h"

using namespace std;


// https://wikidocs.net/51417
// Attribute: �����Ϸ����� �������� ��Ʈ�� �� ���ִ�.

[[namespace::Attribute]]


[[noreturn]] void NoReturnValueFunc()
{
    // ���� ���⿡ �����Ϸ����� � ���� ��ȯ���� �ʰڴٴ� ��ó�� ��������
    // �����Ϸ����� �ڵ� control flow�� caller���� �ٽ� ���ư��� �ʴ´ٴ� ���� �ǹ�;
}

[[noreturn, deprecated("do not use anymore")]]  // ����ϸ� warning�� deprecated �޽����� ����.
void DeprecatedFunction()
{
    ;
}

// C++20 ���� likely, unlikely�� ���ԵǾ���.
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
        [[fallthrough]];    // case9�� ������ default�� ���ڴ�.
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