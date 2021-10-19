//Start Time	: 1817
//End Time		: 1920 구글링 시작.
//통과 유뮤		: O(n^2)를 줄일 방법을 모르겠음. 불통.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

//소수를 구하는 알고리즘 중 
//에라토스테네스의 체 사용
int MySolution(int n) 
{
	int answer = 1;

	for (int i = 3; i <= n; ++i)
	{
		int iCount = 0;
		bool IsPrime = true;

		if ((i & 1) == false)
		{//2제외 짝수면 소수아니니까 넘기기
			continue;
		}

		for (int k = 2; k*k <=i ; ++k)
		{
			if (i%k == 0)
			{				
				IsPrime = false;
				break;
			}
		}

		if (IsPrime)
		{
			++answer;
		}
	}

	return answer;
	//그래도 1시간동안 시간복잡도를 n^2에서
	//n* logn으로 줄였따.
	//하지만 통과는 못함.
}

int EratosthenesSolution(int n)
{
	//해당 수의 제곱근보다 작은 소수들의 배수만 지워서
	//소수를 구하는 방식.
	//왜 제곱근보다 작은 소수의 배수들만 지우냐?
	//만약 n이하의 특정 수 m은
	//m = a * b 로 이루어져 있다.
	//근데 무적권 a와 b 둘 중 하나는 
	//n의 제곱근 보다 작다.
	//그러니까 n의 제곱근보다 작은 소수들의 배수들만 구하면
	//그 짝지어지는 수 b는 구할 필요가 없다 이마리야.
	int answer = 0;
	
	vector<bool> vPrimeCheck(n+1, true);

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (vPrimeCheck[i] == true)
		{
			for (int k = i * i; k <= n; k += i)
			{
				vPrimeCheck[k] = false;
				++answer;
			}
		}
	}

	//for (int i = 2; i<(int)vPrimeCheck.size(); ++i)
	//{
	//	if (vPrimeCheck[i]== false)
	//	{
	//		++answer;
	//	}
	//}
	
	return answer;
}



void main()
{
	EratosthenesSolution(10);

	system("pause");
}