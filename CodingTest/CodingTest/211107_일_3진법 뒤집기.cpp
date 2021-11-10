//Start Time	: 23 42
//End Time		: 00 00
//통과 유뮤		: 2트 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int MySolution(int n)
{
	int answer = 0;


	int iTemp = n;
	vector<int> vec3;
	
	while (true)
	{// 10 to 3

		if (iTemp < 3)
		{
			vec3.emplace_back(iTemp);
			break;
		}

		int Namugi = iTemp % 3;
		iTemp /= 3;
		
		vec3.emplace_back(Namugi);

	
	}

	for (int i = (int)vec3.size() - 1; i >= 0; --i)
	{
		answer += (vec3[i] * (pow(3,(int)vec3.size()-i-1)));
	}



	return answer;
}

void main()
{
	MySolution(45);

	system("pause");
}