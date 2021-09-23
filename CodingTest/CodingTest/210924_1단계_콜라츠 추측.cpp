//Start Time	: 0710
//End Time		: 0725
//통과 유뮤		: pass

#include <iostream>
#include <vector>

using namespace std;

int solution(int num)
{
	int answer = 0;

	long long llNum = num;
	//곱하기 3이 들어가다보니 큰 숫자 들어가면 가끔 오버플로 터침

	while (llNum != 1)
	{
		if (llNum % 2 == 0)
		{//짝수
			llNum /= 2;
		}
		else 
		{//홀수 
			llNum *= 3;
			++llNum;
		}

		++answer;
		
		if (answer > 500)
		{
			return -1;
		}
	}

	return answer;
}

void main()
{
	cout << solution(626331) << endl;



	system("pause");
}