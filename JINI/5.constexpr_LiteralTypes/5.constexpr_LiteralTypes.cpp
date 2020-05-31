#include <iostream>

//  5.1 constexpr 키워드
//      - 상수식이라고 명시함
//      - 객체, 함수 앞에 붙일 수 있는 키워드
//      - 해당 객체, 함수 반환값을 컴파일 시간에 알 수 있음
//		- constexpr, const
//			- cosnt의 경우
//				: b의 값을 지정해주면 후에 바꿀 수 없다
//				int a = 10;
//				const int b = a;
//
//			- constexpr의 경우
//				: 반드시 오른쪽에 다른 상수식이 와야함, a앞에 const 빼면 에러
//				const int a = 10;
//				constexpr int b = a;
//
//		- 함수의 반환형 앞에 constexpr을 추가시 해당 함수의 반환값을 컴파일 타임 상수로 만들 수 있음
//		  대략 컴파일 시간에 계산된다는 소리임
//		
//		- C++ 14 기준 아래 조건 제외하면 constexpr 함수 사용가능 (그전 버전은 return도 하나밖에 안됨)
//			1. goto 문 사용
//			2. 예외 처리 ( * C++ 20부터 try문 가능)
//			3. 리터럴 타입이 아닌 변수 정의
//			4. 초기화 되지 않는 변수 정의
//			5. 실행 중간에 constexpr 이 아닌 함수를 호출

constexpr int Factorial(int _num)
{
	int total = 1;
	for (int i = 1; i <= _num; ++i)
	{
		total *= i;
	}
	return total;
}

template <int NUM>
class Test
{
public:
	int operator()() { return NUM; }
};


//	5.2 literal type
//		- 컴파일러가 컴파일 시간에 정의 할 수 있는 타입
//			1. void
//			2. char, int, bool, long 등 스칼라 타입(기본타입)
//			3. 레퍼런스 타입
//			4. 리터럴 타입의 배열
//			5. 람다 함수 등..
//			  * C++ 14 부터 constexpr 생성자 지원 -> 사용자가 리터럴 타입 만들 수 있음
class Position2D 
{
private:
	int m_ix;
	int m_iy;

public:
	constexpr Position2D(int _x, int _y) : m_ix(_x), m_iy(_y) {}

	constexpr int x() const { return m_ix; }
	constexpr int y() const { return m_iy; }
};

constexpr Position2D AddVec(const Position2D& pos1, const Position2D& pos2) 
{
	return { pos1.x() + pos2.x(), pos1.y() + pos2.y() };
}



int main()
{
	// 5.1 constexpr
	// 헐 이거 완전 좋은듯
	// 포폴 만들때 이거 있었으면 좋겠다고 생각한적있는데.. 있던 기능이었네..
	std::cout << "======================= constexpr =======================" << std::endl;
	std::cout << std::endl;

	constexpr int testArraySize = 30;
	int arr[testArraySize];

	constexpr int testNum = 55;
	Test<testNum> test;
	std::cout << test() << std::endl;

	Test<Factorial(8)> exFactorial;
	std::cout << exFactorial() << std::endl;

	std::cout << std::endl;

	// 5.2 literal type
	std::cout << "======================= literal type =======================" << std::endl;
	std::cout << std::endl;

	constexpr Position2D position1{ 1, 2 };
	constexpr Position2D position2{ 2, 3 };

	Test<position1.x()> a;
	std::cout << a() << std::endl;

	Test<AddVec(position1, position2).x()> b;
	std::cout << b() << std::endl;
}

