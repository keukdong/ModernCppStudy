#include <iostream>

int main()
{
	//rvalue
	//lvalue

	int a = 10;

	//&는 주소를 가지고 있는 lvalue만 참조 가능
	//int& refa = 10;
	int&& refa = 10;
	int& refb = a;

	//lvalue
	//int& foo();
//	foo() = 10;
//	int* p1 = &foo(); //&(&foo)

	//rvalue
//	int foobar();
//	int j = 0;
//	j = foobar();
	//p1 = &foobar();  rvalue의 주소는 참조 불가능
}
