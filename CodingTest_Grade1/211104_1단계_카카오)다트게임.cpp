//Start Time	: 211103 1200	| 211104 1850
//End Time		: 211103 1230	| 211104 1913
//통과 유뮤		: 211103 불통	| 211104 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <math.h>

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

	int iCount = 3;
	string* szTemp = new string[iCount];
	int*	iScoreArr = new int[iCount];
	memset(iScoreArr, 0, sizeof(int)*iCount);
	int	iCurCount = 0;

	bool IsNext = false;

	for (int i = 0; i < (int)dartResult.length(); ++i)
	{
		if (IsNext == true &&
			dartResult[i] >= '0' && dartResult[i] <= '9')
		{
			++iCurCount;
			IsNext = false;
		}

		if (IsNext == false &&
			dartResult[i] >= 'A' && dartResult[i] <= 'Z')
		{
			IsNext = true;
		}

		szTemp[iCurCount] += dartResult[i];
	}

	for (int i = 0; i < iCount; ++i)
	{
		
		iScoreArr[i] = stoi(szTemp[i]);

		for (int k = 0; k < (int)szTemp[i].length(); ++k)
		{
			if (szTemp[i][k] >= '0' && szTemp[i][k] <= '9')
			{
				continue;
			}

			switch ((int)szTemp[i][k])
			{
			case (int)'D':
			{
				iScoreArr[i] = pow(iScoreArr[i], 2);
			}
			break;

			case (int)'T':
			{
				iScoreArr[i] = pow(iScoreArr[i], 3);
			}
			break;

			case (int)'*':
			{
				iScoreArr[i] *= 2;

				if (i >= 1)
				{
					iScoreArr[i - 1] *= 2;
				}
			}
			break;

			case (int)'#':
			{
				iScoreArr[i] *= -1;
			}
			break;

			default:
				break;
			}
		}

	}

	for (int i = 0; i < iCount; ++i)
	{
		answer += iScoreArr[i];
	}

	delete[] iScoreArr;
	delete[] szTemp;

	return answer;
}
void main()
{
	MySolution2("1S*2T*3S");

	system("pause");
} 