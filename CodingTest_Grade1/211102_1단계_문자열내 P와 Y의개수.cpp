//Start Time	: 0921
//End Time		: 0926
//통과 유뮤		: 1트 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

bool MySolution(string s)
{
	bool answer = true;

	int iCountP = 0;
	int iCountY = 0;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == 'p' || s[i] == 'P')
		{
			++iCountP;

			continue;
		}

		if (s[i] == 'y' || s[i] == 'Y')
		{
			++iCountY;

			continue;
		}
				
	}

	if (iCountP != iCountY)
	{
		answer = false;
	}


	return answer;
}

void main()
{


	system("pause");
}