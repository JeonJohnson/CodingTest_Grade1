//Start Time	: 17 17
//End Time		: 17 40 
//통과 유뮤		: 1728 실패 | 17 40 중복제거안하니 되네

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> nums)
{
	int answer = -1;

	vector<int> vecSosu;

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int k = i + 1; k < nums.size(); ++k)
		{
			for (int j = k + 1; j < nums.size(); ++j)
			{
				int iSum = nums[i] + nums[k] + nums[j];
				int iSqrt = sqrt(iSum);
				bool IsSosu = true;

				for (int x = 2; x <= iSqrt; ++x)
				{
					if (iSum % x == 0)
					{
						IsSosu = false;
						break;
					}
				}

				if (IsSosu)
				{
					vecSosu.emplace_back(iSum);
				}
			}

		}

	}


	//vector<int>::iterator UniqueBegin;

	//sort(vecSosu.begin(), vecSosu.end());
	//UniqueBegin = unique(vecSosu.begin(), vecSosu.end());
	//vecSosu.erase(UniqueBegin, vecSosu.end());


	answer = (int)vecSosu.size();

	return answer;
}

void main()
{
	vector<int> temp = { 1,2,7,6,4 };

	solution(temp);

	system("pause");
}