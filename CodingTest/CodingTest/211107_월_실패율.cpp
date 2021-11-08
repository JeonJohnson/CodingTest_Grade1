//Start Time	: 15 11
//End Time		: 16 38
//통과 유뮤		: 3트 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	//answer.reserve(N);
	
	vector<float> vecFail(N,0.f);
	

	vector<int> vecCurStage(N,0);
	vector<int> vecClearStage(N,0);

	for (int i = 0; i < (int)stages.size(); ++i)
	{
		int iClearStage = stages[i] - 2;
		int iCurStage = stages[i] - 1;
	
		for (int j = 0; j <= iCurStage; ++j)
		{
			if (j < (int)vecCurStage.size())
			{
				++vecCurStage[j];
			}
		}

		for (int k = 0; k <= iClearStage; ++k)
		{
			++vecClearStage[k];
		}

	}

	for (int i = 0; i < N; ++i)
	{
		if (vecCurStage[i] == 0)
		{
			vecFail[i] = 0;
		}
		else 
		{
			vecFail[i] = ((int)vecCurStage[i] - vecClearStage[i]) / (float)vecCurStage[i];
		}

		
	}
	
	vector<bool> vecCheck(vecFail.size(), false);

	for (int i = 0; i < vecFail.size(); ++i)
	{

		float fMax = -0.1f;
		int iIndex = 0;

		for (int k = 0; k < vecFail.size(); ++k)
		{
			if (fMax < vecFail[k] && vecCheck[k] == false)
			{
				fMax = vecFail[k];
				iIndex = k;
			}

		}

		vecCheck[iIndex] = true;
		answer.emplace_back(iIndex+1);
	}

	return answer;
}

void main()
{
	vector<int> vecTemp = { 2, 1, 2, 6, 2, 4, 3, 3 };
	vector<int> vecTemp2 = { 4,4,4,4,4 };
	solution(5, vecTemp);

	system("pause");
}