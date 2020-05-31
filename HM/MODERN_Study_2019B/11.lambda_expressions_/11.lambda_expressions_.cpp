#include <iostream>
#include <vector>
#include <functional>

int main()
{
	//람다는 함수 객체와 함수 포인터의 장점만을 가지고 있다
	//함수 객체처럼 class를 선언할 필요가 없다
	//함수의 인라인화가 가능하다(함수 포인터는 불가능)


	//람다  
	//개시자 인자	반환		몸통
	[](int _v)->int {return _v % 6; }(7);
	
	//개시자
	//외부에서 함수 안에 값을 넣어서 사용하고 싶을 때

	int val = 10;
	int a = [val](int _v)->int {return val * _v; }(7);


	//[&]() {}  //외부의 모든 변수를 레퍼런스로 가져오기
	//[=]() {} //외부의 모든 변수를 값으로 가져오기
	//[=, &x, &y] //외부의 모든 변수를 값으로 가져오되 x,y는 레퍼런스로 가져오기
	//[&, x, y] //외부의 모든 변수를 레퍼런스로 가져오되 x,y는 값으로 가져오기
	//[x, &y, z] //지정한 변수들을 지정한 형식으로 가져오기

	int val2 = 5;
	int val3 = 1000;
	float val4 = 2.5f;

	a = [=]()->int {return val4 * val * val2; }();


	//function에 저장할 수도 있다
	std::function<int()> f = [=]()->int {return  val * val2 / 10; };
	a = f();
	
	//리턴 인자값을 지정해 줄 수 있다
	auto test = [=]()->int {return  val4 * val2 / 10; }();
	auto testf = [=]()->auto {return  val4 * val2 / 10; }();

	//딱히 지정해주지 않아도 auto처리 되는 듯
	testf = [=]() {return  val4 * val2 / 10; }();

}
