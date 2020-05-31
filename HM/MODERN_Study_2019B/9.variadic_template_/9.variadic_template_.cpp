
#include <iostream>

template<typename T>
void print(T arg) 
{
    std::cout << arg << std::endl;
}

template<typename T, typename... Types>
void print(T arg, Types... args) 
{
    std::cout << arg << ", ";
    print(args...);
}

template<typename... Types>
void print_Fold(Types... args)
{
   // ((std::cout << args << ", "), ...);


   //(std::cout << ... << args) << std::endl; //기본 원형
   //((std::cout << args), ...) << std::endl; //같은 동작을 함

   // (std::cout << ...<< ", " << args) << std::endl; //컴파일 에러
   ((std::cout << args << ", "), ...) << std::endl;
}

template<typename... Types>
int Add_Fold(Types... args)
{
    return (... + args);
}


int main()
{
    //variadic template(가변 인자 템플릿)
    //typename... Types (템플릿 파라미터 팩)
    //Types... args (함수 파라미터 팩)
    
    print(1, 2.3f, 4, "A");

    //함수를 재귀하면서 인자값의 앞자리를 뺌
    //1, 2.3f, 4, "A"       print(T arg, Types... args)
    //2.3f, 4, "A"          print(T arg, Types... args)
    //4, "A"                print(T arg, Types... args)
    //"A"                   print(T arg) 
    
    //마지막 인자가 하나 남았을 때 다른 함수를 호출하고 스택 총 정리

    //Fold Expression
    //가변 인자 템플릿은 편리하지만 재귀로 구성해야하는 단점이 있다
    //함수 호출을 끝내는 부분을 필수적으로 만들어야 한다
    //하지만 c++17에 도입된 Fold 형식을 사용하면 간단하게 표현 가능

    print_Fold(1, 2.3f, 4, "A");

    int Foldresult = Add_Fold(1, 2, 3, 4);

    // return (... + args);
    // return (((1 + 2) + 3) + 4);

}

