//Start Time	: 2135
//End Time		: 2139
//통과 유뮤		: 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	if (s.length() == 4 || s.length() == 6)
	{
		for (auto& charac : s)
		{
			if ((charac >= 'A' && charac <= 'Z')
				|| (charac >= 'a' && charac <= 'z'))
			{
				answer = false;
				break;
			}
		}
	}
	else { return false; }

	return answer;
}

void main()
{
	solution("a1234");

	system("pause");
}