//Start Time	: 1040
//End Time		: 1046
//통과 유뮤		: 2트 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> MySolution(vector<int> arr, int divisor) 
{
	vector<int> answer;
	answer.clear();

	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] % divisor == 0)
		{
			answer.emplace_back(arr[i]);
		}
	}

	if (answer.size() == 0) //혹은 answer.empty()
	{
		answer.emplace_back(-1);
	}
	else 
	{
		sort(answer.begin(), answer.end(),less<int>());
	}


	return answer;
}

void main()
{


	system("pause");
}