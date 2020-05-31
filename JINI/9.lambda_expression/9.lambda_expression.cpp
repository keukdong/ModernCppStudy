#include <iostream>

// 9.lambda expression(람다식)
//      - 원래 람다는 boost라는 라이브러리에서 제공하는 함수였었음
//
//      - [캡처](전달인자/파라미터) -> return type { 함수 몸통 }
//      - [] 캡처 블록 : 사용시 외부 변수를 캡처해 람다 몸통(?)안에서 사용 가능
//      - () 전달 인자(매개변수)
//      - -> 반환 타입
//      - {} 함수 몸통
//        * 람다는 기본적으로 캡처블록, 전달인자, 반환타입 생략 가능

int main()
{
    // 기본
    [](std::string name) 
    {
        std::cout << "I like a " << name << std::endl;
    }("apple");

    // std::function<void (std::string)>
    auto introduce = [](std::string name) {
        std::cout << "I like a " << name << std::endl;
    };

    introduce("apple");
}
