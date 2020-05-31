#include <iostream>

int main()
{
    //리터럴 타입
    //컴파일러가 컴파일 타임에 정의할 수 있는 타입
    //코드에 직접 삽입된 값

    //void
    //스칼라 타입(char, int, bool, long, float, double)
    //레퍼런스 타입
    //리터럴 타입의 배열

    //혹은 아래를 만족
    //디폴트 소멸자를 가지고 다음중 하나를 만족

    //람다 함수 or
    //arggregate 타입(사용자 정의 생성자, 소멸자가 없으며 모든 데이터 멤버들이 public)
    //constexpr 생성자를 가지며 복사 및 이동 생성자가 없음

    //정수의 리터럴
    int x = 0;
    bool b = true;

    //부동 소수점 리터럴
    double d1 = 3.14584;
    double d2 = 6.02e23;
    double d3 = 1.6e-19;

    //숫자 리터럴에는 유형을 결정하는 접미가 포함되기도 함
    unsigned int val1 = 5u;
    long val2 = 5L;
    float val3 = 5.0f;

    //문자, 문자열 리터럴
    char c = 'A';
    const char* c2 = "string";


    //숫자 리터럴은 기본 10진수
    //8진수는 앞에 0을 붙인다
    x = 012;

    //16진수는 앞에 0x를 붙인다
    x = 0xff;

    //2진수는 0b를 붙인다
    x = 0b1010;

    //긴 리터럴은 c++14부터 숫자에 따옴표를 사용할 수 있다
    int val4 = 10'112'311;
}
