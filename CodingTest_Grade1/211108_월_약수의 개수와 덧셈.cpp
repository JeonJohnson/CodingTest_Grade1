//Start Time	: 14 22
//End Time		: 14 53
//통과 유뮤		: 3트

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int MySolution(int left, int right)
{

	//1		144
	//2		77
	//3		48
	//4		36
	//6		24
	//8		18
	//12	12
	int answer = 0;

	vector<int> vecCount;

	//약수 구하는법 한번 더 숙지하기!
	for (int i = left; i <= right; ++i)
	{
		int iSqrt = (int)sqrt(i);
		int iCount = 0;

		for (int k = 1; k <= iSqrt; ++k)
		{
			if (i % k == 0)
			{
				//약수 자체를 구할 때는
					//여기에서 k자체를 한번 넣고
				if (i / k == k)
				{
					++iCount;
				}
				else
				{
					iCount += 2;
					//약수 자체를 구할 때는
					//이 조건일때 n/k 넣어주면 됨.
				}
			}
		}

		if (iCount & 1)
		{//홀수
			//1과 비트 and연산해서 값이 있다(0이 아니다) = 홀수
			answer -= i;
		}
		else
		{// 짝수
			//1과 비트 and연산해서 값이 없다(0이다) = 짝수
			answer += i;
		}
	}

	return answer;
}

void main()
{
	MySolution(13, 17);

	system("pause");
}