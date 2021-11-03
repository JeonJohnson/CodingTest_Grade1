//Start Time	: 1220
//End Time		:
//통과 유뮤		: 1320에 1트 실패

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int MySolution1(string dartResult)
{
	int answer = 0;

	int		iDartCount = 3;
	bool*	bCheck = new bool[iDartCount];
	memset(bCheck, false, sizeof(bool) * iDartCount);
	int	*	iScoreArr = new int[iDartCount];
	memset(iScoreArr, 0, sizeof(int)* iDartCount);

	string	szTemp;
	//bCheck[0] = true;
	
	int iCurCount = 0;

	bool IsFirstScore = true;

	for (int i = 0; i < dartResult.length(); ++i)
	{
		auto asdf = dartResult[i];

		if (bCheck[iCurCount] == false && (dartResult[i] >= 'A' && dartResult[i] <= 'Z'))
		{
			bCheck[iCurCount] = true;
		}

		if (bCheck[iCurCount] == true && (dartResult[i] >= '0' && dartResult[i] <= '9'))
		{
			//int iScore = 0;
			bool	IsNum = true;
			string szScore;
			for (int k = 0; k < szTemp.length(); ++k)
			{
				if (IsNum)
				{
					if (szTemp[k] >= '0' && szTemp[k] <= '9')
					{
						szScore += szTemp[k];
					}
					else
					{
						iScoreArr[iCurCount]= stoi(szScore);
						IsNum = false;
					}
				}
				else 
				{
					switch ((int)szTemp[i])
					{
					case (int)'S':
					{
						int a = 0;
					}
					break;
					
					case (int)'D':
					{
						pow(iScoreArr[iCurCount], 2);
					}
					break;

					case (int)'T':
					{
						pow(iScoreArr[iCurCount], 3);
					}
					break;
					
					case (int)'*':
					{
						if (iCurCount == 0)
						{
							iScoreArr[iCurCount] *= 2;
						}
						else 
						{
							iScoreArr[iCurCount] *= 2;
							iScoreArr[iCurCount - 1] *= 2;
						}
					}
					break;

					case (int)'#':
					{
						iScoreArr[iCurCount] *= -1;
					}
					break;

					
					default:
						break;
					}
				}
			}	   

			szTemp.clear();
			++iCurCount;
		}
		else 
		{

			szTemp += dartResult[i];

		}
		
		

	}

	for (int i = 0; i < iDartCount; ++i)
	{
		answer += iScoreArr[i];
	}

	delete[] iScoreArr;
	delete[] bCheck;


	return answer;
}

int MySolution2(string dartResult)
{
	int answer = 0;

	return answer;
}
void main()
{
	MySolution1("1S2D*3Y");

	system("pause");
} 