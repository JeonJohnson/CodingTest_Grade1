//Start Time	: 1552
//End Time		:
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string MySolution(string s) 
{
	string answer = "";

	int iStrLen = s.length();

	if (iStrLen & 1)
	{//홀수
		answer = s[(iStrLen - 1) / 2];
	}
	else 
	{//짝수
		answer = s[iStrLen / 2 - 1];
		answer += s[iStrLen / 2];
	}

	
	return answer;
}

void main()
{
	MySolution("abcde");
	MySolution("qwer");

	system("pause");
}