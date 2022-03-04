//Start Time	: 10 22
//End Time		: 11 15
//통과 유뮤		: 53분

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

void GoLeft(int& LeftPos, int iCurNum, string& answer)
{
	answer += 'L';
	LeftPos = iCurNum;
}

void GoRight(int& RightPos, int iCurNum, string& answer)
{
	answer += 'R';
	RightPos = iCurNum;
}

int CalcDist(int iGoalNum, int iCurPos)
{
	if (iGoalNum == 0)
	{
		iGoalNum = 11;
	}

	if (iCurPos == 0)
	{
		iCurPos = 11;
	}


	int iCurPosX = 0, iCurPosY = 0;
	int iGoalPosX = 0, iGoalPosY = 0;

	int iNum = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 3; ++k)
		{
			++iNum;

			if (iNum == iGoalNum)
			{
				iGoalPosX = k;
				iGoalPosY = i;
			}

			if (iNum == iCurPos)
			{
				iCurPosX = k;
				iCurPosY = i;
			}

		}
	}


	return abs(iCurPosX - iGoalPosX) + abs(iCurPosY - iGoalPosY);
}

//[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
string solution(vector<int> numbers, string hand)
{
	string answer = "";

	int iLeftPos = 10;
	int iRightPos = 12;

	vector<int> vecLeft = { 1,4,7 };
	vector<int> vecRight = { 3,6,9 };

	for (int i = 0; i < (int)numbers.size(); ++i)
	{
		int iCurNum = numbers[i];

		switch (iCurNum)
		{
		case 1:
		case 4:
		case 7:
		{
			answer += 'L';
			iLeftPos = iCurNum;
		}
		break;

		case 3:
		case 6:
		case 9:
		{
			answer += 'R';
			iRightPos = iCurNum;
		}
		break;

		default:
		{
			int iGap2Left = CalcDist(iCurNum, iLeftPos);
			int iGap2Right = CalcDist(iCurNum, iRightPos);

			if (iGap2Left < iGap2Right)
			{
				answer += 'L';
				iLeftPos = iCurNum;
			}
			else if (iGap2Left > iGap2Right)
			{
				answer += 'R';
				iRightPos = iCurNum;
			}
			else if (iGap2Left == iGap2Right)
			{
				if (hand == "left")
				{
					GoLeft(iLeftPos, iCurNum, answer);
				}
				else if (hand == "right")
				{
					GoRight(iRightPos, iCurNum, answer);
				}
			}
		}
		break;


		}

	}

	return answer;
}

void main()
{
	
	vector<int> vecTemp = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
	solution(vecTemp, "left");
	
	system("pause");
}