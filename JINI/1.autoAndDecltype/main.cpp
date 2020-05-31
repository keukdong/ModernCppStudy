// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// auto
// auto addFunc(int a, int b) -> int : 후행 반환 형식
auto addFunc(int a, int b)
{
    return a + b;
}

// decltype
class TestDecltype
{
public:
    TestDecltype()
    {
        ftest = 0.0f;
    }
    ~TestDecltype() {}

public:
    float ftest;
};

int main()
{
    // auto와 decltype
    // auto     : 값 타입 추론
    // decltype : 값 타입 추출

    // 1. auto
    // C++11 (VS 2013) : auto 타입 반환 가능
    // C++14 (VS 2015) : auto 반환 시 후행 반환 형식을 지정하지 않아도 타입 추론 가능, decltype(example)형태로 반환 됨
    int c = addFunc(10, 30);



    // 2. decltype Example : 타입 추출 예제
    TestDecltype* declClass = new TestDecltype();
    int iValue = 5;
    const int& ciValue(5);

    decltype(iValue)            declA;               // int
    decltype(declClass->ftest)  declB = 50.0f;       // float
    decltype(ciValue)           declC = declB;       // cosnt int&

    // decltype의 경우 ()로 한번 더 감싸는 경우 참조형(&)이 된다.
    decltype((declClass->ftest)) declD = declB;


    delete declClass;
}