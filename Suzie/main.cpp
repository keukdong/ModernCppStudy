#include <stdio.h>
#include <vector>
#include <iostream>
#include <crtdbg.h>

using namespace std;

void FillVec(vector<int>& vec)
{
	vec.clear();
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i);
	}
}

void PrintVec(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
}

int main()
{	
	vector<int> vecTemp;

	FillVec(vecTemp);
	cout << "for" << endl;
	for (int i = 0; i < 10; ++i)
	{
		vecTemp[i] += 10;
	}
	PrintVec(vecTemp);

	FillVec(vecTemp);
	cout << "Range for" << endl;
	for (auto itr : vecTemp)
	{
		itr += 10;
	}
	PrintVec(vecTemp);

	FillVec(vecTemp);
	cout << "Range for reference iterator" << endl;
	for (auto& itr : vecTemp)
	{
		itr += 10;
	}
	PrintVec(vecTemp);

	return 0;
}