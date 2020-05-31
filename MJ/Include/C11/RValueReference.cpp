
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
    // RValue Reference�� �̸��� ����(��������� ����ų �� ����) �޸𸮸� ����Ű�� ���� ���Ѵ�.
    // �ӽ� ��ü�� ����Ű�� �뵵. 

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
