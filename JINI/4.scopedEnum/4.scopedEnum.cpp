#include <iostream>

// 4. scoped enum (enum class)
//  - C++ 98에선 enum의 경우 범위 제한이 없음(전역 이름 공간에 선언됨)
//  - C++ 11 에서 scoped enum이란 것을 지원하여 제한을 둘 수있음
//    기존 enum의 스코프 문제를 해결하기 위해 나옴
//  - 전방 선언 가능(C++11에선 unscoped enum도 전방 선언가능)
//  - 타입 설정 가능(unscoped enum도 가능)

enum class Fruit
{
    APPLE,
    BANANA,
    CHERRY,
    STRAWBEERRY,
};

// 타입 설정
enum class JOB : std::uint32_t
{
    NONE,
    DOCTOR,
    TEACHER,
    ACHER,
};

int main()
{
    // 기존 enum이라면 불가능함
    auto APPLE = 12;
    Fruit eFuitType = Fruit::APPLE;
}