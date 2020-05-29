
#include "Cpp11.h"


using namespace std;

class InventoryClass
{
public:
    int FindItem(const TCHAR* ItemName) { return -1; }
    bool ConsumeItem(int ItemIndex) { return true; }
};

class PlayerClass
{
    InventoryClass* Inventory;

public:
    InventoryClass* GetInventory() { return Inventory; };

    inline bool IsLocalPlayer() { return true; }
};

auto LambdaExpression() ->int
{
    return 0;
}

static constexpr int InvalidIndex = -1;

auto LambdaExpressionExamples() -> int
{
    // 캐릭터를 가져와서 캐릭터의 Inventory에서 Item이름으로 아이템을 찾을 때

    PlayerClass* Player = nullptr;
    // .. 대충 Player를 가져왔다고 가정

    // 1. lambda를 쓰지 않을 때
    bool bFail = true;

    InventoryClass* Inventory = nullptr;
    if ( Player != nullptr )
    {
        if (Player->IsLocalPlayer())
        {
            Inventory = Player->GetInventory();
        }
    }

    int Index = InvalidIndex;
    if (Inventory != nullptr)
    {        
        Index = Inventory->FindItem(TEXT("HPPotion"));
        if (Index != InvalidIndex)
        {
            if (Inventory->ConsumeItem(Index))
            {
                bFail = false;
            }
        }
    }

    if (bFail)
    {
        // 실패했다면 어떤 작업을 진행
    }

    // ... 그 뒤 작업 진행

    // 2. lambda를 쓸 때
    auto ConsumeItem = [](PlayerClass* InPlayer)
    {
        if (InPlayer == nullptr)
            return false;

        if (!InPlayer->IsLocalPlayer())
            return false;

        auto Inventory = InPlayer->GetInventory();
        if (Inventory == nullptr)
            return false;

        int Index = Inventory->FindItem(TEXT("HPPotion"));
        if (Index == InvalidIndex)
            return false;

        return Inventory->ConsumeItem(Index);
    };

    bFail = ConsumeItem(Player);
    if (bFail)
    {
        // 실패했다면 어떤 작업을 진행
    }

    // ... 그 뒤 작업 진행

    /*
    위 예제에서 람다를 함수 본문에 사용했을 때, 람다를 쓰지 않았을 때보다 2가지 좋아진 점을 확인할 수 있다.
    
    1. 조건에 맞지 않으면(플레이어가 유효하면서, 로컬 플레이어야하고, 인벤토리가 유효하고, 아이템을 찾을 수 있을때)
       바로 false를 return해서 그 뒤의 부가적인 if 검사를 수행하지 않아도 된다.

    2. If 조건검사로 인해 2~3번 중첩된 indent(들여쓰기)를 최소화 할 수 있고
       적절한 함수 이름을 사용한다면 가독성 측면에서 보기 좋은 코드가 된다. 
    */

    return 0;
}
