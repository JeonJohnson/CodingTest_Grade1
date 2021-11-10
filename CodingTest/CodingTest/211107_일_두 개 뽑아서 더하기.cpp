//Start Time	: 2245
//End Time		: 2306
//통과 유뮤		: 2트 성공

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> MySolution(vector<int> numbers)
{
	vector<int> answer;

	for (int i = 0; i < (int)numbers.size(); ++i)
	{
		for (int k = i + 1; k < (int)numbers.size(); ++k)
		{
			int iSum = numbers[i] + numbers[k];

			if (find(answer.begin(), answer.end(), iSum) == answer.end())
			{
				answer.emplace_back(iSum);
			}
		}
	}
	
	sort(answer.begin(), answer.end(), less<int>());

	return answer;
}

void main()
{
	vector<int> Numbers = { 2,1,3,4,1 };
	MySolution(Numbers);


	system("pause");
}