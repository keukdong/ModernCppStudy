
#include "Cpp11.h"

using namespace std;

// cpp reference examples

template <class T>
void Swap(T& a, T& b)
{
    //static_assert(std::is_copy_constructible<T>::value, "Swap requires copying");

    auto TempVar = a;
    a = b;
    b = TempVar;
}

struct Complex
{
    float Real;
    float Imaginary;

    Complex(const Complex&) {};
    Complex(float InReal, float InImaginary)
        : Real(InReal)
        , Imaginary(InImaginary)
    {
    };
    Complex() = default;
};

struct EventBase
{
protected:
    string EventName;
    int Value;

public:
    EventBase(string InName, int InValue)
        : EventName(InName)
        , Value(InValue)
    {};

    virtual void ProcessEvent() {};
};

/* Dynamic cast 실험한 것*/
/*
struct InheritedEvent : public EventBase
{

public:    
    InheritedEvent()
        : EventBase("ItemEvent", 1)
    {
    }

public:
    virtual void ProcessEvent() override {};
};

class EventManager
{
public:
    template<class T>
    void ProcessEvent(T* InEvent)
    {
        EventBase* CastedEvent = dynamic_cast<EventBase*>(InEvent);
        if (CastedEvent == nullptr)
        {
            return;
        }

        InEvent->ProcessEvent();
    }
};

*/
auto Staticassertion() -> int
{
    static_assert(true, L"message");

    Complex A, B;
    Swap(A, B);     // Swap requires copying

    //EventManager EventMgr;
    //
    //InheritedEvent Event1;
    //EventMgr.ProcessEvent(&Event1);

    return 0;
}
