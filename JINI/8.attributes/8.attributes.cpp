#include <iostream>

// 8. attribute
//		- C++11부터 타입, 오브젝트, 함수 등 컴파일러에게 알려..?힌트..?를 줄 수 있음.
//		- 메타데이터로부터 컴파일러가 코드 흐름 제어의 변경, 컴파일 경고 제공/제거 등 동작들을 수행함
//		- [[ ]] 이렇게 2개씩 써줘야함
//      - 몰라도 코딩하는 것에는 문제 없지만.. 편리성을 위해서 알아두면 좋음
//
//		8.1 [[noreturn]]
//			- C++11
//			- 함수 선언에서만 사용
//			- 함수가 실행된 이후 caller에게 control(?) 넘어가지않음
//			- 호출에 관련된 임시 객체들을 저장하지 않아도 됨
//
//		8.2 [[deprecated]], [[deprecated("reason")]]
//			- C++14
//			- 가급적 사용하지 않는것을 권고할때 사용
//
//      8.3 [[fallthrough]]
//          - C++17
//          - switch문 - case/default 코드 바로 앞에 위치해야 됨, 끝에는 사용할 수 없음
//
//      8.4 [[maybe_unused]]
//          - C++17


// 8.1 [[noreturn]]
[[noreturn]] void NoreturnFunc()
{
    int a = 0;
}

void NoreturnTest()
{
    NoreturnFunc();

    // NoreturnFunc() 수행이후 caller에게 흐름이 넘어오지 않고,
    // 하위 코드들은 모두 제거됨 (그냥 날림)
    std::cout << "룰루룰루" << std::endl;
}

//8.2 [[deprecated]], [[deprecated("reason")]]
[[deprecated]] void DeprecatedFunc(int i)
{
    if (i > 0)
        throw "positive";
}

[[deprecated("가급적 사용하지마셈")]] void DeprecatedReasonFunc(int i)
{
    if (i > 0)
        throw "positive";
}


int main()
{
}