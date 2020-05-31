#include <iostream>

// rvalue 참조
//
// 1. l-value, r-value ?
//  - l-value : 대입시 왼쪽 or 오른쪽에 오는 식, 단일 표현식 이후에도 사라지지 않음 (ex.변수)
//  - r-value : 오직 오른쪽에만 오는 식, 단일 표현식 이후에 사라짐 (ex.임시객체, 상수)
//
//  좌측값은 어떤 메모리 위치를 가리킴, & 연산자를 통해 해당 위치 참조 가능
//
//  ex. ++a (l-value), a++ (r-value)
//
//
//  2. r-value 참조
//  - 복사를 하지 않고 임시객체를 그대로 사용하는 것.
//    r-value를 l-value 참조처럼 이용하는 것
//
//  - 사용하는 이유
//   : 오버헤드를 줄일 수 있음
//     임시 객체를 복사하지 않아도 되어 데이터양이 많을 경우 효율적임
//
// 3. std::move
// - C++11부터 사용 가능
//   인자로 받은 것을 r-value으로 변경함

class Test
{
private:
    int idata;

public:
    Test() : idata(5)
    {
        std::cout << "constructor : " << idata << std::endl;
    }

    // l-value 참조
    Test(int& _lvalue) : idata(_lvalue)
    {
        std::cout << "lvalue reference : " << idata << std::endl;
    }

    // r-value 참조
    // 이동 생성자
    Test(int&& _rvalue) :idata(_rvalue)
    {
        std::cout << "rvalue reference : " << idata << std::endl;
    }

    ~Test() {}

public:
    void print()
    {
        std::cout << "idata 값 : " << idata << std::endl;
    }

};

int main()
{
    // l-value
    int ilValue = 3;
    Test lt = Test(ilValue);
    lt.print();

    // r-value
    Test rt = Test(10);
    rt.print();
}