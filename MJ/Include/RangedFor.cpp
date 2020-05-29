
#include "Cpp11.h"


using namespace std;

auto RangedFor() -> int
{
    //  자동 iterator의 역할을 한다.

    list<int> List;
    vector<int> Vector;
    unordered_map<int, string> UnorderedMap;

    for (auto& Item : List)
    {
        // Something
    }

    for (auto& Item : Vector)
    {
        // Something
    }

    UnorderedMap.insert(make_pair<int, string>(2, string("Two")));
    for (auto& Item : UnorderedMap)
    {
        auto First = Item.first;
        auto Second = Item.second;
    }

    return 0;
}

class VeryBigClass
{
    // 엄청 큰 크기의 클래스
};

auto RangedForExamples() -> int
{
    vector<VeryBigClass> Vector;

    for (auto ItemWithValue : Vector)
    {
        // 값복사로 객체를 "복사"해서 가져온다
        // 복사 비용이 존재한다.
    }

    for (auto& ItemWithReference : Vector)
    {
        // 레퍼런스로 객체를 참조한다
    }

    return 0;
}
