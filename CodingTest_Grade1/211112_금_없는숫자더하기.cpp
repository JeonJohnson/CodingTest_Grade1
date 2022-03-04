//Start Time	: 0905
//End Time		: 0908
//통과 유뮤		: 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> numbers)
{
	int answer = 0;

	sort(numbers.begin(), numbers.end());

	int k = 0;
	for (int i = 0; i <= 9; ++i)
	{
		if (i != numbers[k])
		{
			answer += i;
		}
		else { ++k; }

	}

	return answer;
}

void main()
{


	system("pause");
}