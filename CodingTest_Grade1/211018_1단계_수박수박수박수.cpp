//Start Time	: 20 27
//End Time		: 20 30
//통과 유뮤		: 한번

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string MySolution(int n) 
{
	string answer = "";

	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 == 0)
		{
			answer += "박";
		}
		else 
		{ 
			answer += "수";
		}

	}

	return answer;
}

string OtherSolution(int n) {
	string answer = "";

	for (int i = 0; i < n; i++)
	{
		i & 1 ? answer += "박" : answer += "수";
		//1과의 and 비트연산으로 홀/짝수를 구분하여 
		//숫자를 추가함.
	}


	return answer;
}

void main()
{
	MySolution(4);

	system("pause");
}