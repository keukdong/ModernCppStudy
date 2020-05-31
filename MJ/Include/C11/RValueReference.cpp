
#include "Cpp11.h"


using namespace std;

class VeryBigSizeClass
{
    static constexpr int MaxSize = 10000;
    
    int TestValue = 1;
    int* VeryBigMemory = nullptr;
    
public:
    VeryBigSizeClass(int InValue)
    {
        TestValue = InValue;
        VeryBigMemory = new int[MaxSize];
    }
    ~VeryBigSizeClass()
    {
        if (VeryBigMemory)
            delete[] VeryBigMemory;

        VeryBigMemory = nullptr;
    }

    VeryBigSizeClass(const VeryBigSizeClass& Other)
    {
        TestValue = 2;
        VeryBigMemory = new int[MaxSize];
    }

    VeryBigSizeClass(VeryBigSizeClass&& Other)
    {
        TestValue = 3;
        VeryBigMemory = Other.VeryBigMemory;

        Other.TestValue = -1;
        Other.VeryBigMemory = nullptr;
    }
};

VeryBigSizeClass GetValue()
{
    return VeryBigSizeClass(1000);
}

auto RValueReference() -> int
{
    // RValue Reference란 이름이 없는(통상적으로 가리킬 수 없는) 메모리를 가리키는 것을 뜻한다.
    // 임시 객체를 가리키는 용도. 

    return 0;
}

auto MoveConstructor() -> int
{
    auto Test0 = GetValue(); /* TestValue : 1000, VeryBigMemory : Valid */
    auto Test1(GetValue());  /* TestValue : 1000, VeryBigMemory : Valid */

    auto Test2(std::move(GetValue()));  /* TestValue : 1000, VeryBigMemory : Valid */

    auto Test3(VeryBigSizeClass(1));

    return 0;
}
