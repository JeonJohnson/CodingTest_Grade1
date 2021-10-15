//Start Time	: 2325
//End Time		:
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int MySolution(int n)
{
	int answer = 0;

	string szTemp = to_string(n);

	for (int i = 0; i < (int)szTemp.length(); ++i)
	{
		char szArr[255] = {szTemp[i]};
		answer += atoi(szArr);
	}

	return answer;
}

int OtherSolution_1(int n)
{
	int answer = 0;

	string szTemp = to_string(n);

	for (int i = 0; i < (int)szTemp.length(); ++i)
	{
		answer += szTemp[i] - '0';
		//아스키 코드의 정수값은
		// '0' = 48
		// '1' = 49
		// '2' = 50
		//... ...
		// '9' = 57
		//처럼 48로 시작해 1씩 늘어남으로 - '0' 하면 찐 정수값이 나온다.
	}

	return answer;
}

int OtherSoluition_2(int n)
{
	int answer = 0;
	//몇번 나온 각 자리수 정수 구하는 법.
	while (n) 
	{
		answer += n % 10;
		n /= 10;
	}
	return answer;
}


void main()
{

	MySolution(123);

	system("pause");
}