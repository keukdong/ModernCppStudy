#include <iostream>
#include <cstddef>

int main()
{
	//nullptr
	//기존의 NULL의 문제점을 대체하기 위해 만들어짐
	//NULL은 0으로 쓰였음

	//같은 의미
	int* ptr1 = 0;
	int* ptr2 = NULL;


	//리터럴로 0을 사용하는 경우 null과 0을 구분할 수 없는 상황이 발생

	switch (NULL)
	{
	case 0:
		std::cout << "0입니다" << std::endl; //여기로 들어옴
		break;
	default:
		std::cout << "default입니다" << std::endl;
		break;
	}

	//정수 타입 0인지를 판단하는 검사에 걸리게 된다.
	//이 문제를 해결하기 위해 c++11에서 nullptr을 도입 rvalue 상수다
	//c++은 암시적으로 nullptr을 모든 유형의 포인터로 변환

	//nullptr을 int* 형의 정수 포인터를 변환 후 nullptr의 내부 값을 할당
	int* ptr3 = nullptr;


	//nullptr을 대입하면 각 자료형의 포인터로 알아서 변환시킨다
	void Pushprt_int(int* _ptr);
	void Pushprt_float(float* _ptr);
	void Pushprt_double(double* _ptr);


	//c++11 에서는 std::nullptr_t 키워드 도입(cstddef 헤더)
	//nullptr_t은 nullptr 하나의 값 만을 가질 수 있다.

	void Pushprt(int* _ptr);
	void Pushprt(std::nullptr_t _ptr);

	//함수 오버로딩에 사용함으로서 null값이 들어오는 순간만을 분류할 수 있다
}

