#include <iostream>
#pragma warning(disable : 4101)

int factorial(int n) 
{
    int total = 1;
    for (int i = 0; i < n; i++) 
    {
        total *= i;
    }

    return total;
}

constexpr int factorial_constexpr(int n)
{
    int total = 1;
    for (int i = 0; i < n; i++)
    {
        total *= i;
    }

    return total;
}



template<int N>
struct A
{
    int operator()(){return N; }
};

int main()
{
    //c++에는 두가지 종류의 상수가 있다
    
    //런타임 상수(runtime constant)
    //초기값을 런타임에서만 확인 가능
    //컴파일러가 컴파일 시 값을 결정할 수 없음

    //사용자의 입력을 받고 나서야 할 수 있다
    int val;
    std::cin >> val;
    const int EnterVal(val);

    //인자값으로 무엇이 들어올지 모른다
    void fuc(const int _pramVal);

  
    //컴파일 시간 상수(compile-time constant)
    //컴파일 시간에 초기값을 확인 가능
    const int val2(10);
    const int val3(10 + 10);


    //상수식 : 컴파일러가 컴파일 타임에 어떠한 식의 값을 결정할 수 있다
    //정수상수식 : 상수식 중 값이 정수

    //배열의 크기는 정수상수식이어야 함
    //int arr[val] = { 0, };  컴파일 에러가 난다
    int arr2[val2] = { 0, };

    //템플릿 인자는 상수식이어야함
    //A<val> fac1;컴파일 에러가 난다
    A<val2> fac2;

    //enum의 값을 지정할 때는 정수상수식이어야 함
    enum Etest 
    {
        val_1 = 0,
        val_2 = val2,
       // val_3 = val 컴파일 에러가 난다
    };
   

    //constexpr 키워드를 사용한 상수는 컴파일 시간 상수여야 함
    //constexpr : 해당 객체나 함수의 리턴 값을 컴파일 타임에 알 수 있다 라는 뜻 = 상수식
    constexpr int test1(10);
    constexpr int test2(10 + 10);

    //constexpr 변수의 오른쪽은 반두시 다른 상수식이 와야함
    //int temp = 3;
    //constexpr int test3(val);  컴파일 에러
    //constexpr int test4(temp); 컴파일 에러

    //정수상수식을 사용하는 자리에 에러 없이 잘 들어감
    int arr_constexpr[test1] = { 0, };
    enum Etest2 
    {
        constexpr_val_1 = test1,
        constexpr_val_2 = test2,
    };
 

 
    //constexpr 함수

    //A<factorial(5)> a; 컴파일 에러가 난다
    //factorial(5)의 리턴값은 컴파일 타임 상수가 아니기 때문에

    A<factorial_constexpr(5)> a; //함수 앞에 constexpr키워드를 붙여 상수식을 반환하게 한다


    //c++ 11 에서는 constexpr함수에 제약이 많았음
    //함수 내부에서 변수 정의X
    //return은 딱 하나만 등등

    //c++ 14부터는 제약이 완화되어 아래 조건 빼고 모두 함수내부에서 수행 가능
    //goto문 사용 불가
    //리터럴 타입이 아닌 변수의 정의 불가
    //초기화되지 않는 변수 정의 불가
    //실행 중간에 constexpr가 아닌 함수 호출 불가


    //위 제약을 어기면 컴파일 오류 발생


    //constexpr 생성자
    //constexpr로 객체를 생성할 경우 constexpr 함수의 제약을 모두 받는다
    //생성자의 인자들은 반드시 리터럴 타입이어야만 한다

    {
        class vector2 
        {
        private:
            int m_ix;
            int m_iy;

        public:
            constexpr vector2(int _x, int _y) : m_ix(_x), m_iy(_y) {}

            constexpr int x() const { return m_ix; }
            constexpr int y() const { return m_iy; }
        };


        constexpr vector2 vec1(1, 2);

        //vec1은 constexpr로 만들어진 상수식이기 때문에 
        //정수상수식을 사용하는 자리에 에러 없이 잘 들어감
        A<vec1.x()> classtest1;  
    }
}

