//Start Time	: 01 47
//End Time		: 02 30
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int>  MySolution(vector<int> answers)
{
	vector<int> answer;

	//vector<int> Student1;
	//vector<int> Student2;
	//vector<int> Student3;

	int iSel1 = 1, iSel2 = 2, iSel3 = 3;
	//int iScore1= 0 , iScore2= 0, iScore3 = 0;

	//vector<int> vecScore(3, 0);

	vector<int> vecScore(3,0);
	//학생,점수

	int iCount2 = 0, iCount3 = 0;
	for (int i = 0; i < (int)answers.size(); ++i)
	{
		if (answers[i] == iSel1)
		{
			++vecScore[0];
		}
		if (answers[i] == iSel2)
		{
			++vecScore[1];
		}
		if (answers[i] == iSel3)
		{
			++vecScore[2];
		}


		iSel1 == 5 ? iSel1 = 1 : ++iSel1;
		

		if (iSel2 == 2)
		{
			if (iCount2 == 1)
			{
				iCount2 = 3;
			}
			else if(iCount2 == 5) 
			{
				iCount2 = 1;
			}
			else 
			{
				iCount2++;
			}

			iSel2 = iCount2;
		}
		else 
		{
			iSel2 = 2;
		}

		if (iCount3 == iSel3)
		{
			//3 1 2 4 5 

			switch (iSel3)
			{
			case 3:
			{
				iSel3 = 1;
			}
			break;

			case 2:
			{
				iSel3 = 4;
			}
			break;

			case 5:
			{
				iSel3 = 3;
			}
			break;

			case 1:
			case 4:
			{
				++iSel3;
			}
			break;

			default:
				break;
			}
		}
		else 
		{
			iCount3 = iSel3;
		}
	}

	int iHighScore = *(max_element(vecScore.begin(), vecScore.end()));
	
	for (int i = 0; i < 3; ++i)
	{
		if (vecScore[i] == iHighScore)
		{
			answer.emplace_back(i+1);
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}



vector<int> OtherSolution(vector<int> answers) 
{
	vector<int> one = { 1,2,3,4,5 };
	vector<int> two = { 2,1,2,3,2,4,2,5 };
	vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };

	vector<int> answer;

	vector<int> they(3);

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == one[i%one.size()])
		{
			they[0]++;
		}
		if (answers[i] == two[i%two.size()]) 
		{
			they[1]++; 
		}

		if (answers[i] == thr[i%thr.size()]) 
		{
			they[2]++;
		}
	}

	int they_max = *max_element(they.begin(), they.end());

	for (int i = 0; i < 3; i++)
	{
		if (they[i] == they_max) answer.push_back(i + 1);
	}
	return answer;
}

void main()
{
	vector<int> an1 = { 1,2,3,4,5 };
	vector<int> an2 = { 1,3,2,4,2 };
	
	MySolution(an2);

	system("pause");
}