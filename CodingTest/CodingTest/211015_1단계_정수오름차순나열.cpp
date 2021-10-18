//Start Time	: 1800
//End Time		: 1837
//통과 유뮤		: 2번의 오탑 후 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

long long MySolution(long long n) 
{
	long long answer = 0;

	string szTemp =	to_string(n);
	
	int asdf = szTemp.length();

	for (int i = 0; i < (int)szTemp.length()-1; ++i)
	{
		int iLartgest = 0;
		int iIndex = -1;

		for (int k = i; k < (int)szTemp.length()-1; ++k)
		{
			char temp[255] = { szTemp[k] };

			if (atoi(temp) > iLartgest)
			{
				
				iLartgest = atoi(temp);
				iIndex = k;
			}

			//if (szTemp[k] < szTemp[k + 1])
			//{
			//	char temp = szTemp[k];
			//	szTemp[k] = szTemp[k + 1];
			//	szTemp[k + 1] = temp;
			//}
		}
		if (iIndex != -1)
		{
			char temp = szTemp[i];
			szTemp[i] = szTemp[iIndex];
			szTemp[iIndex] = temp;
		}
	}

	answer = std::stoll(szTemp);

	return answer;
}

long long GoodSolution(long long n)
{
	long long answer = 0;

	string str = to_string(n);
	sort(str.begin(), str.end(), greater<char>());
	answer = stoll(str);

	return answer;
}

void main()
{


	cout << MySolution(118372) << endl;
	cout << MySolution(12345) << endl;
	cout << MySolution(5678) << endl;
	cout << MySolution(926) << endl;

	system("pause");
}