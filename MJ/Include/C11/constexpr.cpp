
#include "Cpp11.h"

using namespace std;

class ConstexprClass
{
    // class constexpr�� ��������� ���� �� ����.
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
    // static const ���� ������ ���� �ѹ��� �ʱ�ȭ �� �� �� �ڿ� �ٲ��� �ʴ´�.
    static const int StaticConstInt = InValue;

    /* constexpr�� ������ Ÿ�Ӷ� �� ���� �˰� �־���Ѵ�. */
    //constexpr int ConstexprInt = InValue; // (error)

    const int ConstInt = InValue;

    return 0;
}

int ConstexprExamples()
{
    // �Ϲ������� ����� ����, constexpr�� ���� ���������� �� ���� � �뵵�� �������� �� �� �ִ�.
    auto Item1 = GetItemfromSlot(0);
    
    constexpr int SlotFirstIndex = 0;
    auto Item2 = GetItemfromSlot(SlotFirstIndex);

    return 0;
}
