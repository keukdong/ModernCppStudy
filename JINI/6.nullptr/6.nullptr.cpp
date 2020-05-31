#include <iostream>
#include <cstddef>

//	6. nullptr
//		- C++11 기준으로 nullptr 사용 가능 (r-value)
//		- 포인터는 인스턴스화 될 때 초기화 되지 않음, 값이 할당되지 않을 경우 이상한 주소를 가리킴
//		- null값을 가진 포인터를 null 포인터라고 함
//		- 포인터에 다른 값을 지정하지 않을 경우 null값으로 초기화하는 것이 좋음
//		- 리터럴 0으로 포인터에 0을 할당할 경우 null포인터인지 정수 0인지 컴파일러가 확인할 수 없어서 문제가 생길 수 있음
//		- std::nullptr_t : nullptr 하나의 값만 가질 수 있는데 nullptr를 매개변수로 받아야하는 함수를 만들 때 사용하면 좋음 <cstddef> 헤더 추가해야함
//
//		* 어쩐지 회사에서는 nullptr 안쓰고 NULL 쓰더라 -.-;;

void Test(std::nullptr_t _ptr)
{
	std::cout << "Test(std::nullptr_t)" << std::endl;
}

class A
{
public:
	A() {}
	~A() {}
};

void main()
{
	A* a = new A();
	A* aa = nullptr;
	//Test(aa);
	//Test(a);
	Test(nullptr);

	delete a;
}