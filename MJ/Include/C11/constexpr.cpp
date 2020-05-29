
#include "Cpp11.h"

using namespace std;

class ConstexprClass
{
    // class constexpr를 멤버벼눗로 가질 수 없다.
    //constexpr int TestClassVariable = 2;
    static constexpr int TestClassVariable = 2;
};

class ItemClass
{
};

ItemClass* GetItemfromSlot(int SlotIndex) { return nullptr;  };

int Constexpr(int InValue)
{
    static constexpr int Test1 = 3;
    constexpr int Test2 = 4;

    // constexpr vs const
    // static const 지역 변수는 최초 한번만 초기화 된 후 그 뒤에 바뀌지 않는다.
    static const int StaticConstInt = InValue;

    /* constexpr은 컴파일 타임때 그 값을 알고 있어야한다. */
    //constexpr int ConstexprInt = InValue; // (error)

    const int ConstInt = InValue;

    return 0;
}

int ConstexprExamples()
{
    // 일반적으로 상수를 쓸때, constexpr을 쓰면 직관적으로 이 값이 어떤 용도로 쓰였는지 알 수 있다.
    auto Item1 = GetItemfromSlot(0);
    
    constexpr int SlotFirstIndex = 0;
    auto Item2 = GetItemfromSlot(SlotFirstIndex);

    return 0;
}
