
#include <iostream>

template<class T>
void swap(T& a, T& b) 
{
    static_assert(std::is_copy_constructible<T>::value, "Swap requires copying");
    static_assert(std::is_nothrow_constructible<T>::value &&
        std::is_nothrow_assignable<T>::value, "Swap may throw");

    auto c = b;
    b = a;
    a = c;
}


int main()
{
    //기존 assertion은 프로그램 실행 중 예외를 감지해내기 위해 사용되었다

    //c++11에 컴파일 타임에 체크하여 assertion을 수행할 수 있게 해주는 static assertion가 추가
    //대표적 사용처는 각종 type traits 클래스
    //컴파일 타임에 템플릿 인자의 타입 특성 체크 하는데 

    


}