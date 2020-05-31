#include <iostream>

int add(int _x, int _y)
{
	return _x + _y;
}

auto addauto(int _x, int _y)->int //후행반환 형식
{
	return _x + _y;
}

/*
매개 변수로는 사용할 수 없다
void autoTest(auto _x, auto _y)
{
	std::cout << _x + _y << std::endl;
}
*/

int main()
{
	//auto
	  //타입 추론
	auto d = 5.0;
	auto f = 5.0f;

	//함수 반환 값으로도 받을 수 있다
	auto a = add(1, 4);
	auto a_auto = addauto(1, 4); //c++14에서 함수 반환 타입을 자동으로 추론할 수 있도록 확장
}