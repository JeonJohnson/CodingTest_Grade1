//Start Time	: 2307
//End Time		: 2340
//통과 유뮤		: 2트 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int MySolution(vector<int> d, int budget)
{
	int answer = 0;

	sort(d.begin(), d.end(), less<int>());
	
	int iMaxCount = 0;
	int iCount = 0;
	int iStart = 0;
	int iSum = 0;

	while (true)
	{
		for (int i = iStart; i < (int)d.size(); ++i)
		{
			iSum += d[i];
			
			if (iSum <= budget)
			{
				++iCount;

				if (iCount > iMaxCount)
				{
					iMaxCount = iCount;
				}
			}
			else 
			{
				break;
				
			}
		}

		++iStart;
		iSum = 0;
		iCount = 0;
		
		if (iStart > (int)d.size())
		{
			break;
		}
	}

	answer = iMaxCount;
	return answer;
}

int OtherSolution(vector<int> d, int budget) 
{
	int answer = 0;

	sort(d.begin(), d.end());

	int sum = 0;
	for (int i = 0; i < d.size(); i++)
	{
		if (budget - d[i] >= 0)
		{
			budget -= d[i];
			answer++;
		}
		else
		{
			break;
		}
	}

	return answer;
	//ㅋㅋ 예산에서 빼주면 더 간단!
}

void main()
{
	vector<int> vecTemp = { 1,3,2,5,4 };
	MySolution(vecTemp,9);

	system("pause");
}