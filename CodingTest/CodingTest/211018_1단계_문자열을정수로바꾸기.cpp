//Start Time	: 20 00
//End Time		: 20 25
//통과 유뮤		: 1번 불통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

//놀랍지만 stoi를 쓰면 부호까지 바꿔준다!!

int MySolution(string s) 
{
	int answer = 0;

	int iTemp = 0;

	for (int i = (int)s.length()-1; i >= 0; --i)
	{
		if (s[i] != '-' && s[i] != '+') 
		{
			answer += (s[i] - '0') * (pow(10,iTemp));
			++iTemp;
		}
	}

	if (s[0] == '-')
	{
		answer *= -1;
	}

	return answer;
}

int OtherSolution(string s) 
{
	int answer = stoi(s);
	return answer;
}

void main()
{
	MySolution("+9250");
	
	system("pause");
}