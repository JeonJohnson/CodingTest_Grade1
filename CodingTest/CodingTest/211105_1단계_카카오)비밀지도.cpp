//Start Time	: 1720
//End Time		: 1755 
//통과 유뮤		: 3트 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;

	vector<int> vecResult;
	vector<int> vecTemp;

	for (int i = 0; i < n; ++i)
	{
		vecResult.emplace_back(arr1[i] | arr2[i]);

		vecTemp.clear();

		int iTemp = vecResult[i];

		while (true)
		{
			vecTemp.emplace_back(iTemp % 2);
			iTemp /= 2;

			if (iTemp <= 1)
			{
				vecTemp.emplace_back(iTemp);

				if (vecTemp.size() < n)
				{
					while (true)
					{
						vecTemp.emplace_back(0);
						if (vecTemp.size() == n)
						{
							break;
						}
					}
				}
				break;
			}
		}

		string szTemp;
		for (int k = vecTemp.size() - 1; k >= 0; --k)
		{
			if (vecTemp[k] == 0)
			{
				//answer[i] += to_string(vecTemp[k]);
				szTemp += ' ';
			}
			else
			{
				szTemp += '#';
			}
		}

		answer.emplace_back(szTemp);
	}

	//문자열로 바꾸는 과정을 한번  거치지말고 바로 해주면 더 깔끔할듯?




	return answer;

}

vector<string> UpgradeSolution(int n, vector<int> arr1, vector<int> arr2)
{
	//문자열로 바꾸는 과정을 바로 넣어보자.

	vector<string> answer;
	vector<int> vecResult;

	for (int i = 0; i < n; ++i)
	{
		string szTemp;
		vecResult.emplace_back(arr1[i] | arr2[i]);

		for (int k = 0; k < n; ++k)
		{
			if (vecResult[i] % 2 == 0)
			{
				szTemp = " " + szTemp;
			}
			else 
			{
				szTemp = "#" + szTemp;
			}
			//요런식으로 "넣을문자" + "원래문자열" 해주면 for문 거꾸로 안돌려도 됨.
			vecResult[i] /= 2;
			//vecResult[i] = vecReuslt[i] >> 1;
			//나누기2는 오른쪽 비트연산으루다가!
		}
		
		answer.emplace_back(szTemp);
	}


	return answer;
}



void main()
{
	vector<int> Temp1 = { 46, 33, 33 ,22, 31, 50 };
	vector<int> Temp2 = { 27 ,56, 19, 14, 14, 10 };

	solution(6, Temp1, Temp2);

	system("pause");
}