#include <iostream>
#include <crtdbg.h>

template <typename T>
void swap(T& _a, T& _b) 
{
	std::cout << "swap" << std::endl;
	T temp = _a;
	_a = _b;
	_b = temp;
}

template <typename T>
void swap_rval(T& _a, T& _b)
{
	std::cout << "swap_rval" << std::endl;
	T temp = std::move(_a);
	_a = std::move(_b);
	_b = std::move(temp);
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//move semantics  (move 문법)
	//perfect forwarding (완벽한 전달)

	//move constructor c++ (이동 생성자)
	//c++ 생성자는 기본 생성자, 복사 생성자, 이동 생성자가 있다
	//포인터를 멤버로 가지는 클래스는 복사 생성자에서 깊은 복사를 수행

	//이동 생성자는 Rvalue Referencxe를 인자로 받는 새로운 타입의 생성자
	//이동 생성자는 호출되면 얕은 복사를 하고 원본의 소유권을 대상으로 move를 실행
	//원본 객체를 NULL로 처리하고 접근할 수 없게 한다

	{
		class MoveTest 
		{
		private:
			char* Name;
			int age;

		public:
			MoveTest(const char ch[], int n) 
			{
				Name = new char[strlen(ch) + 1];
				strcpy_s(Name, sizeof(char) * (strlen(ch) + 1),ch);
				age = n;
			}

			~MoveTest() 
			{
				delete[] Name;
			}

			MoveTest(const MoveTest& Other) : age(Other.age)
			{
				//복사 생성자 (깊은 복사)
				Name = new char[strlen(Other.Name) + 1];
				strcpy_s(Name, sizeof(char) * (strlen(Other.Name) + 1), Other.Name);
				std::cout << "Copy constructor" << std::endl;
			}

			MoveTest(MoveTest&& Other) noexcept
			{
				//이동 생성자 - 소유권 이전
				age = Other.age;
				Name = Other.Name;

				Other.age = 0;
				Other.Name = nullptr;
				std::cout << "Move constructor" << std::endl;
			}

			MoveTest& operator= (const MoveTest& Other)
			{
				if (this == &Other)
					return *this;

				//삭제 후
				delete[] Name;

				//재할당
				Name = new char[strlen(Other.Name) + 1];
				strcpy_s(Name, sizeof(char) * (strlen(Other.Name) + 1), Other.Name);

				age = Other.age;

				//복사 대입 연산자
				std::cout << "Copy assignment operator" << std::endl;

				return *this;
			}

			MoveTest& operator= (MoveTest&& Other) noexcept
			{
				//이동 대입 연산자
				if (this == &Other)
					return *this;

				age = Other.age;
				Name = Other.Name;

				Other.age = 0;
				Other.Name = nullptr;

				std::cout << "Move assignment operator" << std::endl;
				return *this;
			}
		};

		//MoveTest c1("dei", 10);
		//MoveTest c2 = c1; //lvalue를 넘김으로서 복사가 됌
		//MoveTest c3 = std::move(c1); //rvalue를 넘김으로서 이동


		MoveTest f1("f1", 10);
		MoveTest f2("f2", 100);

		MoveTest f3("f3", 10);
		MoveTest f4("f4", 100);

		swap<MoveTest>(f1, f2);
		swap_rval<MoveTest>(f3, f4);

		//swap의 경우 대입 연산마다 깊은 복사를 위해 동적 할당과 해제를 반복
		//swap_rval는 소유권만 이전 후 기존객체의 접근을 제한하며 해제의 역할을 소멸자에 맡기기 때문에
		//훨씬 비용이 적게 들어간다
	}
}
