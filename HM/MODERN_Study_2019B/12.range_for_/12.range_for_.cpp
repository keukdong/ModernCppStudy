#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

int main()
{
    //범위 기반 for
    //배열 내를 전부 돌며 함수구문을 실행


    //number에는 처음에는 0이 대입되고 루프 실행마다 ++
    //루프를 반복할 배열에 원소가 남지 않을 때까지 실행함
    int arr[10] = { 1,2,3,4,5,4,8,9,4,1 };
    for (int number : arr)
        std::cout << number << " ";

    for (auto number : arr) //더 유연하게 쓰기 위해 auto 
        std::cout << number << " ";

    for (const auto& number : arr) //온전히 읽기 전용으로 쓰이게 하기 위해//참조로 쓰여 비용이 적고 수정될 일이 없다
        std::cout << number << " ";


    std::cout << "\n\n\n\n";
    std::cout << "STL 테스트" << std::endl;

    std::vector<int> testVec;
    std::list<int> testList;
    std::set<int>   testSet;
    std::map<int, int>   testMap;

    for (int i = 0; i < 10; i++) 
    {
        testVec.push_back(10 - i);
        testList.push_back(10 - i);
        testSet.insert(10 - i);
        testMap.insert(std::pair<int, int>(10 - i, i));
    }

    std::cout << "\n\n";
    std::cout << "vector" << std::endl;

    for (int number : testVec)
        std::cout << number << " ";

    std::cout << "\n\n";
    std::cout << "list" << std::endl;
    for (int number : testList)
        std::cout << number << " ";
    
    std::cout << "\n\n";
    std::cout << "set" << std::endl;
    for (int number : testSet)
        std::cout << number << " ";

    std::cout << "\n\n";
    std::cout << "map" << std::endl;

   /* for (std::pair<int, int> number : testMap)
    {
        std::cout << number.first << " ";
        std::cout << number.second << " ";
    }*/

    for (auto number : testMap)
    {
        std::cout << number.first << " ";
        std::cout << number.second << " ";
    }  

    return 0;
}
