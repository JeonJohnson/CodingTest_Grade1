//Start Time	: 1808
//End Time		: 1820
//통과 유뮤		: 통이긴한디... 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int MySolution(int n)
{
	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (n % i == 1)
		{
			answer = i;
			break;
		}
	}

	return answer;
}

void main()
{
	MySolution(12);

	system("pause");
}