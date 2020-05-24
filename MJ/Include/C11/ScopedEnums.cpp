
#include "Cpp11.h"


using namespace std;

enum class EDialogueType : unsigned __int8
{
    None = 0,

    Conversation,
    Event,
    SelectableOption,

    Max
};

enum ETest
{
    None = 0,
    Max
};

struct FDialogue
{
    EDialogueType Type;
    vector<string> Scripts;
};

void UpdateNextDialogueInStart() {};
void UpdateNextDialogueInEnd() {};

int ScopedEnums()
{
    /*
        scoped enum = enum class
        ���� enum�� ���� enum class(scpoed enum)�� �ٸ���
    */

    /* 1. enum class �� ĳ������ ���� ������ �������� ���� ���Ѵ�. */
    unsigned int EnumVariable = None;
    // unsigned __int8 EnumClassVariable = EDialogueType::Conversation; -> error
    unsigned __int8 EnumClassVariable = static_cast<unsigned __int8>(EDialogueType::Conversation);

    /* 2. enum ���� �׸��� �̸��� ������ � �������� �׸��� ����Ű���� ��ȣ������. */
    enum test1
    {
        Red,
        Green,
        Blue
    };

    enum test2
    {
        Red,
        Green,
        Blue
    };

    unsigned int WhichEnumVariable = Red;   // test2�� Red�� ��������� test1�� Red�� ������ �ִ�.

    enum class Test1
    {
        Red,
        Green,
        Blue
    };

    enum class Test2
    {
        Red,
        Green,
        Blue
    };

    auto ClearlyItisTest2EnumVariable = Test2::Red; // name scope�� ���� �Ǳ� ������ �ǹ̰� ��Ȯ������.

    return 0;
}

int ScopedEnumExamples()
{
    vector<FDialogue> Dialogues;

    for (auto Dialogue : Dialogues)
    {
        switch (Dialogue.Type)
        {
        case EDialogueType::Conversation:
            UpdateNextDialogueInEnd();
            break;

        case EDialogueType::Event:
        case EDialogueType::SelectableOption:
            UpdateNextDialogueInStart();
            break;

        default:
            PrintLog(TEXT("Invalid Dialogue Type"));
        }
    }

    return 0;
}

