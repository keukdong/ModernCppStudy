
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
        기존 enum에 비해 enum class(scpoed enum)이 다른점
    */

    /* 1. enum class 는 캐스팅을 하지 않으면 컴파일을 하지 못한다. */
    unsigned int EnumVariable = None;
    // unsigned __int8 EnumClassVariable = EDialogueType::Conversation; -> error
    unsigned __int8 EnumClassVariable = static_cast<unsigned __int8>(EDialogueType::Conversation);

    /* 2. enum 안의 항목의 이름이 같으면 어떤 열거자의 항목을 가리키는지 모호해진다. */
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

    unsigned int WhichEnumVariable = Red;   // test2의 Red를 쓰고싶은데 test1의 Red로 잡히고 있다.

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

    auto ClearlyItisTest2EnumVariable = Test2::Red; // name scope가 강제 되기 때문에 의미가 명확해진다.

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

