//Start Time	: 2118
//End Time		: 2122
//통과 유뮤		: 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string solution(vector<string> seoul)
{
	string answer = "";

	for (int i = 0; i < (int)seoul.size(); ++i)
	{
		if (seoul[i] == "Kim")
		{
			answer = "김서방은 " + to_string(i) + "에 있다";
		}
	}

	return answer;
}

void main()
{


	system("pause");
}