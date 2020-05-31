#include <iostream>
#include <cstring>

// 이동 생성자(move constructors), 이동 할당/대입 연산자(move Assignmenet)
//
// 이동 생성자를 사용하면 r-vlaue 개체가 리소스 복사 X, l-value로 이동가능
//

class Test
{
private:
    char* m_pstringData;
    unsigned int m_istringLength;
    unsigned int m_curMemorySize;

public:
    Test() 
    {
        std::cout << "기본 생성자    :   Test()" << std::endl;
        m_istringLength = 0;
        m_curMemorySize = 0;
        m_pstringData = nullptr;
    }
    ~Test() 
    {
        //if (nullptr != m_pstringData)
        //{
        //    delete m_pstringData;
        //}
        //m_pstringData = nullptr;
    }

    // 생성자
    Test(const char* _test)
    {
        std::cout << "기본 생성자    :   Test (const char*)" << std::endl;
        m_istringLength = strlen(_test);
        m_curMemorySize = m_istringLength;
        m_pstringData = new char[m_istringLength];

        for (int i = 0; i < m_istringLength; ++i)
        {
            m_pstringData[i] = _test[i];
        }

        Print();
    }

    // 복사 생성자
    Test(const Test& _test)
    {
        std::cout << "복사 생성자    :   Test(const Test&)" << std::endl;
        m_istringLength = _test.m_istringLength;
        m_curMemorySize = _test.m_curMemorySize;
        m_pstringData = new char[m_istringLength];

        for (int i = 0; i < m_istringLength; ++i)
        {
            m_pstringData[i] = _test.m_pstringData[i];
        }

        Print();
    }

    // 이동 생성자
    Test(const Test&& _test)
    {
        std::cout << "이동 생성자    :   Test(const Test&&)" << std::endl;
        m_istringLength = _test.m_istringLength;
        m_curMemorySize = _test.m_curMemorySize;
        m_pstringData = _test.m_pstringData;

        Print();
    }

public:
    Test operator+(const Test& _test)
    {
        Test test;
        test.Reserve(m_istringLength + _test.m_istringLength);

        for (int i = 0; i < m_istringLength; i++)
        {
            test.m_pstringData[i] = m_pstringData[i];
        }

        for (int i = 0; i < _test.m_istringLength; i++)
        {
            test.m_pstringData[m_istringLength + i] = _test.m_pstringData[i];
        }

        test.m_istringLength = m_istringLength + _test.m_istringLength;
        return test;
    }

public:
    void Reserve(int size)
    {
        if (size > m_curMemorySize)
        {
            char* prevStringData = m_pstringData;

            m_pstringData = new char[size];
            m_curMemorySize = size;

            for (int i = 0; i != m_istringLength; i++)
            {
                m_pstringData[i] = prevStringData[i];
            }

            if (nullptr != prevStringData)
            {
                delete[] prevStringData;
            }
        }
    }

    void Print()
    {
        for (int i = 0; i < m_istringLength; ++i)
        {
            std::cout << m_pstringData[i];
        }

        std::cout << std::endl;
    }
};

int main()
{
    // 이동 생성자
    Test constructors1("Apple");
    Test constructors2("Banana");

    std::cout << "===================================================" << std::endl;

    Test moveConstructors = constructors1 + constructors2;

    // 이동 대입 연산자
}