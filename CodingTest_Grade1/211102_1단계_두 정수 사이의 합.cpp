//Start Time	: 1045
//End Time		: 1052
//통과 유뮤		: 1트 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

long long MySolution(int a, int b) 
{
	long long answer = 0;

	int iBig;
	int iSmall;

	if (a > b)
	{
		iBig = a;
		iSmall = b;
	}
	else if (a < b)
	{
		iBig = b;
		iSmall = a;
	}
	else if (a == b)
	{
		return a;
	}

	for (int i = iSmall; i <= iBig; ++i)
	{
		answer += i;
	}
	
	return answer;
}

long long OtherSolution_1(int a, int b) 
{
	//비트연산 매니아
	long long answer = 0;

	if (a > b)
	{
		a ^= b ^= a ^= b;
	}
	answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;

	return answer;
}

long long OtherSolution_2(int a, int b)
{
	//시그마 공식을 사용.
	return (long long)(a + b) * (abs(a - b) + 1) / 2;
}


void main()
{
	//solution(5, 3);

	system("pause");
}