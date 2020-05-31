#include <iostream>

// 10. range for (Ranged-based for loops / 맞나..범위기반for문)
//      - for(element_declaration:array)
//          statement;
//      element_declaration : 배열요소와 같은 자료형을 가져야 됨, auto 키워드 사용하면 편함
//
//		- 범위기반 for문에서는 참조 or const 참조 사용하는 것이 좋음
//		- 배열 말고 STL 벡터, 리스트, 셋, 맵같은 것도 사용 가능

int main()
{
	int testArray[] = { 5, 4, 23, 49, 98, 125, 438 }; 
	for (auto number : testArray)
		std::cout << number << ' ';

	// 참조해서 배열 복사
	int Testarray1[5] = { 9, 7, 5, 3, 1 };
	for (auto& element : Testarray1)
		std::cout << element << ' ';
}