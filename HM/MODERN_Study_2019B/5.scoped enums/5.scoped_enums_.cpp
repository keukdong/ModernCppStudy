#include <iostream>

int main()
{
    //c++ 98의 enum은 범위 제한이 없다
    //모든 이름 공간에 선언이 되어버린다;

    enum color_98
    {
        BALCK,
        WHITE,
        RED
    };

    //auto RED = false; //이게 가능하게 된다

    enum class color_scoped 
    {
        BALCK,
        WHITE,
        RED
    };

    int color = RED; //color_98의 RED
    color_scoped color_e = color_scoped::RED; //color_scoped의 RED
    
    //아래 사항들은 컴파일 에러가 난다
    //scoped은 타입 검사가 까다롭기 때문에 자료형과 네임스페이스를 명시해줘야한다
    //int color_e = color_scoped::RED;  
    //color_scoped color_e = RED;
    //color_scoped color_e = 0;

    auto color_a = color_scoped::RED; //이건 됌



    //기존 enum의 정수 계통 암시적 변환을 허용하지 않는다
    //변환을 하고싶다면 static_cast를 사용해서 명시적 캐스팅을 해야한다
    color = static_cast<int>(color_scoped::RED);



    //scoped enum은 전방선언이 가능
    //사실 기존 이넘도 가능하긴 했다(c++ 11부터)

    //c++의 모든 enum은 컴파일러가 숨겨진 타입(underlying type)을 결정한다
    //enum color{ red, yellow, blue }; 가 있다면 이것은 char 타입으로 지정(1바이트면 표현하기에 충분)

    //만약 이런 넓은 범위의 값이 들어간다면 
    //숨겨진 타입을 이 enum을 표현할 수 있을 정도의 큰 값으로 설정할 것
    enum test_Big 
    {
        _a = 0,
        _b = 100,
        _c = 0xFFFFFFF,
        _d = 0xFFFFFFFF
    };

    
    //바로 이런 숨겨진 타입(underlying type) 때문에 전방선언을 할 수 없다
    //컴파일러가 최적화를 위해 숨겨진 타입을 결정해야하는데 
    //전방선언으로는 크기를 알 수 없기 때문
    enum class test_defult; //기본적으로 int 4바이트

    enum class test_uint32 : std::uint32_t; //형을 지정할 수 있다
    enum class test_uint64 : std::uint64_t;

   
   //c++ 11부터 기본 이넘에서도 타입을 지정할 수 있다.
   //타입을 지정해주면 컴파일러가 숨겨진 타입을 지정해주지 않아도 됨으로 전방 선언 가능
   enum unscoped_uint64 : std::uint64_t;
   int size = sizeof(unscoped_uint64); //결과 8바이트가 나옴

}
