//Start Time	: 1753
//End Time		: 1757
//통과 유뮤		: 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

long long MySolution(int price, int money, int count)
{
	long long answer = -1;
	long long iTotalPrice = 0;

	for (int i = 0; i < count; ++i)
	{
		iTotalPrice += price * (i + 1);
	}
	
	answer = iTotalPrice - money;

	if (answer <= 0)
	{
		answer = 0;
	}


	return answer;
}

long long OtherSolution(int price, int money, int count)
{
	long long answer = (long long)(count * (count + 1) / 2) * price;
	//가우스 공식 1부터 n까지의 합 n(n+1)/2 로 구할 수 있다.
	return answer > money ? answer - money : 0;
}

void main()
{


	system("pause");
}