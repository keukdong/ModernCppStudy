#include <iostream>

// 7. variadic temapltes (가변 길이 템플릿)
//		- 매개 변수를 여러개 받을 수 있는 템플릿
//		  파라미터 팩의 경우 템플릿의 타입앞에 ...을 붙이고, 함수는 타입 뒤에 ...를 붙임
//
//		- template <typename T, typename... Types>
//			: typename... (typename+...) -> 템플릿 파라미터 팩
//			  0개 이상의 템플릿 인자를 말함
//
//		- void Print(T _arg, Types... _args)
//			: 파라미터에 ...로 오는 것 -> 함수 파라미터 팩
//			  0개 이상의 함수 인자를 말함

template <typename T>
void Print(T _arg)
{
	std::cout << _arg << std::endl;
}

template <typename T, typename... Types>
void Print(T _arg, Types... _args)
{
	std::cout << _arg;
	Print(_args...);
}

int main()
{
	Print(1, 2, 3, 4, 0.5f, 123.49f, "하이룽 안뇽안뇽");
	Print("디로링  ", "과자냠 ", "메론빙수 먹고싶다...");
}
