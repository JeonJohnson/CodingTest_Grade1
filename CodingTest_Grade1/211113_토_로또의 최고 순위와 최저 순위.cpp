//Start Time	: 0700
//End Time		: 0725
//통과 유뮤		: 1트통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int CalcGrade(int _MatchCount)
{
	if (_MatchCount >= 2)
	{
		return abs(_MatchCount - 6) + 1;
	}
	else
	{
		return 6;
	}
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;
	//lo 0, 0, 1, 25, 31, 44
	//wi 1, 6, 10, 19, 31, 45

	//lo 0, 0, 
	//wi  6, 10, 19,  45
	
	//당첨된 번호랑 안된번호 다 빼기
	//sort(lottos.begin(), lottos.end());
	//sort(win_nums.begin(), lottos.end());

	int iMatchCount = 0;
	int iMinGrade = 0;
	int iMaxGrade = 0;

	
	for (auto iter = lottos.begin(); iter != lottos.end();)
	{
		if (*iter == 0)
		{
			++iter;
			continue;
		}

		auto iterFind = find(win_nums.begin(), win_nums.end(), *iter);

		if (iterFind != win_nums.end())
		{
			++iMatchCount;

			win_nums.erase(iterFind);
			iter = lottos.erase(iter);
		}
		else 
		{ 
			iter = lottos.erase(iter);
		}
	}
	
	iMinGrade = CalcGrade(iMatchCount);

	iMaxGrade = CalcGrade(iMatchCount + lottos.size());

	answer.emplace_back(iMaxGrade);
	answer.emplace_back(iMinGrade);



	return answer;
}

void main()
{


	system("pause");
}