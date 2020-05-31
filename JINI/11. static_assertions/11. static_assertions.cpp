#include <iostream>

// 11. static_assert
//		- C++11부터 사용 가능
//		- 컴파일 타임에 검사해서 assertion(assert문같은거)함
//		- C++11 : static_assert(bool_constexpr(상수표현식), message(컴파일 에러 메세지))  
//		- C++14	: static_assert(bool_constexpr) 이거 추가됨, 컴파일 에러 메세지 없는 함수 추가

#include <type_traits>

template <class T>
void swap(T& a, T& b)
{
    static_assert(std::is_copy_constructible<T>::value, "Swap requires copying");
    static_assert(std::is_nothrow_move_constructible<T>::value
        && std::is_nothrow_move_assignable<T>::value,
        "Swap may throw");
    auto c = b;
    b = a;
    a = c;
}

template <class T>
struct data_structure
{
    static_assert(std::is_default_constructible<T>::value,
        "Data Structure requires default-constructible elements");
};

struct no_copy
{
    no_copy(const no_copy&) = delete;
    no_copy() = default;
};

struct no_default
{
    no_default() = delete;
};

int main()
{
    int a, b;
    swap(a, b);

    no_copy nc_a, nc_b;
    swap(nc_a, nc_b); // 1

    data_structure<int> ds_ok;
    data_structure<no_default> ds_error; // 2
}
