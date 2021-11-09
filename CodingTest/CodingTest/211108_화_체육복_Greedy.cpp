//Start Time	: 2128
//End Time		: 2330
//통과 유뮤		: 약 8트 만에 성공.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

//n -> 전체 학생의 수 
//lost -> 체육복 없는새기
//reserve -> 체육복 여분 있는 친구 

//bool findPair(pair<bool, int> temp1)
//{
//	//return temp1.second == iCondition;
//}

class FindFunc
{
public:
	FindFunc(int condition)
		:iCondition(condition)
	{}
	
public:
	bool operator() (pair<bool, int> temp1)
	{
		return temp1.second == iCondition;
	}

	void SetCondition(int i)
	{
		iCondition = i;
	}

private:
	int iCondition;

};

int MySolution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	   
	vector<pair<bool, int>> vecLost;
	vector<pair<bool, int>> vecReserve;	
	//vecTemp.reserve(lost.size());

	for (int i = 0; i < (int)lost.size(); ++i)
	{
		vecLost.emplace_back(make_pair(false, lost[i]));
	}

	for (int i = 0; i < (int)reserve.size(); ++i)
	{
		vecReserve.emplace_back(make_pair(false, reserve[i]));
	}

	sort(vecLost.begin(), vecLost.end());
	sort(vecReserve.begin(), vecReserve.end());


	//여벌을 가져왔지만 딱낀 친구는 로스트에서 제외.
	for (int i = 0; i < vecReserve.size(); ++i)
	{
		int iTemp = vecReserve[i].second;

		vector<pair<bool,int>>::iterator iter;

		for (iter = vecLost.begin(); iter != vecLost.end();)
		{
			if ((*iter).second == iTemp)
			{
				iter = vecLost.erase(iter);
				vecReserve[i].first = true;
				break;
			}
			else 
			{
				++iter;
			}
		}
		//for (int k = 0; k < vecLost.size(); ++k)
		//{
		//	if (vecLost[k].second == iTemp)
		//	{
		//		vecReserve[i].first = true;
		//		vecLost[k].first = true;
		//		break;
		//	}
		//}
	}
	
	int iPerson = n;

	for (int i = 0; i < vecLost.size(); ++i)
	{
		if (vecLost[i].first == false)
		{
			--iPerson;
		}
	}

	for (int i = 0; i < (int)vecLost.size(); ++i)
	{
		int iLost = vecLost[i].second;
		FindFunc cFind1(iLost-1);
		FindFunc cFind2(iLost + 1);

		auto iterFindPre = find_if(vecReserve.begin(), vecReserve.end(), cFind1);
		auto iterFindNext = find_if(vecReserve.begin(), vecReserve.end(), cFind2);

		if (iterFindPre != vecReserve.end() && (*iterFindPre).first == false)
		{//앞 친구가 가지고 있을 경우
			(*iterFindPre).first = true;
			vecLost[i].first = true;
		}
		else 
		{
			if (iterFindNext != vecReserve.end() && (*iterFindNext).first == false)
			{//뒷친구가 가지고 일을 경우
				(*iterFindNext).first = true;
				vecLost[i].first = true;
			}
		}
	}
	
	for (int i = 0; i < vecLost.size(); ++i)
	{
		if (vecLost[i].first == true)
		{
			++iPerson;
		}
	}

	answer = iPerson;

	return answer;
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	int student[35];

	for (int i : reserve)
	{
		student[i] += 1;
	}

	for (int i : lost) 
	{
		student[i] += -1;
	}

	for (int i = 1; i <= n; i++) 
	{
		if (student[i] == -1) 
		{
			if (student[i - 1] == 1)
			{
				student[i - 1] = student[i] = 0;
			}
			else if (student[i + 1] == 1)
			{
				student[i] = student[i + 1] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (student[i] != -1) answer++;
	}
	return answer;
}


void main()
{

	vector<int> lost = { 1,3,2 };
	vector<int> reserve = { 4,2 };

	solution(5, lost, reserve);

	system("pause");
}