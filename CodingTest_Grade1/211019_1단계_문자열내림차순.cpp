//Start Time	: 2140
//End Time		: 2154
//통과 유뮤		: 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string MySolution(string s)
{
	string answer = "";

	//int* iArr = new int[s.length()];
	vector<int> iArr;
	//int* iUpper = new int[s.length()];
	vector<int> iUpper;


	for (int i = 0; i < (int)s.length(); ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{//소문자 먼저 넣기
			iArr.emplace_back(static_cast<int>(s[i]));
		}
	}
	sort(iArr.begin(), iArr.end(), greater<int>());
	for (auto& element : iArr)
	{
		answer += element;
	}


	for (int i = 0; i < (int)s.length(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{//대문자
			iUpper.emplace_back(static_cast<int>(s[i]));
		}
	}
	sort(iUpper.begin() , iUpper.end(), greater<int>());
	for (auto& element : iUpper)
	{
		answer += element;
	}


	return answer;
}

string OtherSolution(string s)
{
	//아스키 코드 기준
	//대문자 A ~ Z => 65~90
	//소문자 a ~ z => 97~122
	
	sort(s.begin(), s.end(), greater<char>());
	int i = 0;
	return s;
}

void main()
{
	OtherSolution("Zbcdefg");

	system("pause");
}