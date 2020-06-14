
#include "C11/Cpp11.h"


// 가변인자 함수. 옛날에도 가능했다. printf가 그러하다
// https://m.blog.naver.com/PostView.nhn?blogId=psychoria&logNo=220291160479&proxyReferer=https:%2F%2Fwww.google.com%2F
// c++10 가변인자를 템플릿에 적용할 수 있게 되었다. 

template<class ...Types>
void Func(Types ...args) {};

// parameter pack이 없을 때 그대로 출력하기 위한 override함수
void PrintTemplate(const char *format)
{
    std::cout << format;
}

// typename ...TArgs 이런 것을 템플릿 파라미터 팩 (가변인자팩)이라고 부른다.
// 0개 이상의 템플릿 인자
template<typename ...TArgs, typename T>
void PrintTemplate(const char* format, T value, TArgs ...args)
{
    for (; *format != '\0'; ++format)
    {
        if (*format == '%')
        {
            std::cout << value;
            PrintTemplate(format + 1, args...);
            return;
        }
        std::cout << *format;
    }
}

// printf 기능 구현
int PrintFunc(const char* _Format, ...)
{
    int _Result = 0;
    va_list _ArgList;   // 가변 인자의 시작 주소를 가리키는 포인터  char*

    /*
     __crt_va_start(_ArgList, _Format);  // 가변인자 중 첫번째 인자의 주소를 가르쳐주는 매크로
    _Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    */


    // #define va_start(ap, v)  ( (ap) = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
    return _Result;
}

template<class ...Args>
void LambdaCaptureFunc(Args ...args)
{
    auto LambdaFunc = [&, args...]{ return Func(args); };
    LambdaFunc();
}


auto VariadicTemplate() -> int
{
    Func();
    Func(1);
    Func(2, 3.f);

    // value : HelloWorld / args... : '!', 123
    // value : '!'        / args... : 123
    // value : 123        / args... : NULL parameter pack
    PrintTemplate("%world% %\n", "HelloWorld", '!', 123);
   
    return 0;
}

/*
    C++11 이전의 템플릿은 템플릿을 선언할 때, 인자의 수를 명시할 수 밖에 없었음
    -> 가변인자를 구현하려면 지원하고 싶은 인자의 수마다 템플릿을 정의해줘야했다.
*/

template<typename T, typename C1, typename C2, typename C3, typename C10>
void DoSomething(T* t, C1 c1, C2 c2, C3 c3, C10 c10)
{
};

// VS2010년의 tuple코드가 저렇게 작성되어있다
// 가변인자 지원 템플릿은 과도한 코드 중복에 시달려야했다.

template<typename T, typename ...Args>
void DoSomething(T* t, const Args&& ...args)
{
};

// ... 를 parameter pack이라고 부른다. 

