
#include "Cpp11.h"


using namespace std;

auto RangedFor() -> int
{
    //  �ڵ� iterator�� ������ �Ѵ�.

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
    // ��û ū ũ���� Ŭ����
};

auto RangedForExamples() -> int
{
    vector<VeryBigClass> Vector;

    for (auto ItemWithValue : Vector)
    {
        // ������� ��ü�� "����"�ؼ� �����´�
        // ���� ����� �����Ѵ�.
    }

    for (auto& ItemWithReference : Vector)
    {
        // ���۷����� ��ü�� �����Ѵ�
    }

    return 0;
}
