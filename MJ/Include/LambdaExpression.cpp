
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
    // ĳ���͸� �����ͼ� ĳ������ Inventory���� Item�̸����� �������� ã�� ��

    PlayerClass* Player = nullptr;
    // .. ���� Player�� �����Դٰ� ����

    // 1. lambda�� ���� ���� ��
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
        // �����ߴٸ� � �۾��� ����
    }

    // ... �� �� �۾� ����

    // 2. lambda�� �� ��
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
        // �����ߴٸ� � �۾��� ����
    }

    // ... �� �� �۾� ����

    /*
    �� �������� ���ٸ� �Լ� ������ ������� ��, ���ٸ� ���� �ʾ��� ������ 2���� ������ ���� Ȯ���� �� �ִ�.
    
    1. ���ǿ� ���� ������(�÷��̾ ��ȿ�ϸ鼭, ���� �÷��̾���ϰ�, �κ��丮�� ��ȿ�ϰ�, �������� ã�� �� ������)
       �ٷ� false�� return�ؼ� �� ���� �ΰ����� if �˻縦 �������� �ʾƵ� �ȴ�.

    2. If ���ǰ˻�� ���� 2~3�� ��ø�� indent(�鿩����)�� �ּ�ȭ �� �� �ְ�
       ������ �Լ� �̸��� ����Ѵٸ� ������ ���鿡�� ���� ���� �ڵ尡 �ȴ�. 
    */

    return 0;
}
