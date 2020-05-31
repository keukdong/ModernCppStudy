#include <iostream>


[[noreturn]] int f1()
{
	int a = 10;
	return a;
}

[[deprecated]] void fun2(int i)
{
	int a = 10;
}

[[deprecated("Will be removed in the next version")]] void fun3(int i)
{
	int a = 10;
}

[[nodiscard]] int bar() 
{
	return 3;
}

int main()
{
	//attributes
	//c++ 11 부터 지원되는 기능으로 자료형, 객체, 코드 등에서 정의된 실행 속성을 지정
	//일종의 메타데이터인 힌트들로부터 컴파일러는 코드 흐름 제어의 변경, 컴파일 경고를 제ㅈ공 혹 제거하는 행동을 수행


	//noreturn  //[[noreturn]] 
	//함수 선언에서만 사용가능
	//함수에 붙이면 값을 반환하지 않겠다고 하는데 컴파일 에러는 안 걸린다?
	//컴파일러에게 코드 control flow상 caller에게 돌아가지 않음을 의미
	//caller한테 control이 돌아오지 않는다

	int a = f1();  //warning C4645: 'noreturn'으로 선언된 함수에 return 문이 있습니다.


	//deprecated // [[deprecated]]
	//클래스, typedef, 변수, 함수, 열거형, 템플릿 특수화 선언에 붙일 수 있다.
	//사용은 가능하나 가급적 쓰지 않기를 권고할 때

	//fun2(15); //error C4996: 'fun2': deprecated로 선언되었습니다.

	//속성 앞에 넣어준 문구로 에러 문구를 띄워줄 수 있다!
	//fun3(15); // error C4996: 'fun3': Will be removed in the next version


	//[[nodiscard]]
	//함수, 열거형, 클래스 선언에서 사용 가능
	//컴파일러에게 값이 버려질 경우 컴파일 경고를 냄
	auto i = (bar(), 55); // warning C4834: 'nodiscard' 특성이 포함된 함수의 반환 값을 버리는 중

	//[[maybe_unused]]
	//함수, 열거형, 클래스,변수, typedef에서 미사용시에도 경고를 발생하지 않게 하기
}

