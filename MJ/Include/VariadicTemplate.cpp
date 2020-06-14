
#include "C11/Cpp11.h"


// �������� �Լ�. �������� �����ߴ�. printf�� �׷��ϴ�
// https://m.blog.naver.com/PostView.nhn?blogId=psychoria&logNo=220291160479&proxyReferer=https:%2F%2Fwww.google.com%2F
// c++10 �������ڸ� ���ø��� ������ �� �ְ� �Ǿ���. 

template<class ...Types>
void Func(Types ...args) {};

// parameter pack�� ���� �� �״�� ����ϱ� ���� override�Լ�
void PrintTemplate(const char *format)
{
    std::cout << format;
}

// typename ...TArgs �̷� ���� ���ø� �Ķ���� �� (����������)�̶�� �θ���.
// 0�� �̻��� ���ø� ����
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

// printf ��� ����
int PrintFunc(const char* _Format, ...)
{
    int _Result = 0;
    va_list _ArgList;   // ���� ������ ���� �ּҸ� ����Ű�� ������  char*

    /*
     __crt_va_start(_ArgList, _Format);  // �������� �� ù��° ������ �ּҸ� �������ִ� ��ũ��
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
    C++11 ������ ���ø��� ���ø��� ������ ��, ������ ���� ����� �� �ۿ� ������
    -> �������ڸ� �����Ϸ��� �����ϰ� ���� ������ ������ ���ø��� ����������ߴ�.
*/

template<typename T, typename C1, typename C2, typename C3, typename C10>
void DoSomething(T* t, C1 c1, C2 c2, C3 c3, C10 c10)
{
};

// VS2010���� tuple�ڵ尡 ������ �ۼ��Ǿ��ִ�
// �������� ���� ���ø��� ������ �ڵ� �ߺ��� �ô޷����ߴ�.

template<typename T, typename ...Args>
void DoSomething(T* t, const Args&& ...args)
{
};

// ... �� parameter pack�̶�� �θ���. 

