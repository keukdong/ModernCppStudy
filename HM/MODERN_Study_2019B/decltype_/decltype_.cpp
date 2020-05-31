#include <iostream>

struct STest
{
	float f;
};

template<typename T, typename U>
auto Add(T _t, U _u)//->decltype(_t + _u) c++14부터 에러 없이 반환 타입 추론
{
	return _t + _u;
}

//decltype(auto)로 후행반환과 같은 형태를 갖춤
template <typename T, typename U>
decltype(auto) add_template(T&& x, U&& y)//-> decltype(std::forward<T>(x) + std::forward<U>(y))
{
	return std::forward<T>(x) + std::forward<U>(y);
}

int main()
{
	int x = 0;
	decltype(x) y = x; 	//값으로부터 자료형을 추출

	STest* StructTemp = new STest();
	decltype(StructTemp->f) fTemp;
	delete StructTemp;

	auto a = Add<float, double>(0.5f, 1.0);
	auto b = Add<int, float>(2, 1.0f);

	auto T1 = add_template(1, 2);
}
