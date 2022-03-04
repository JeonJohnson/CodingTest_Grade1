//Start Time	: 0730
//End Time		: 0808
//통과 유뮤		: none

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, int m)
{
	//최대공약수(GCD) 구하는 법 -> 소인수 분해 후 공통된 소인수를 곱하면 됨.
		//or 유클리드 호제법 사용 => 큰수에서 작은수를 나눈 나머지를 따로 보관한 뒤
		//몫에서 나머지를 나눠서 딱 떨어질 때 까지 반복.
	//최소공배수(LCM) 구하는 법 -> 소인수 분해 후 모든 소인수를 곱하면 됨.
		//or 두수의 곱에 최대공약수를 나눈 몫

	vector<int> answer;
	
	int GCD = 0;
	int LCM = 0;

#pragma region MySolution
	//int a, b,c;

	//if (n >= m)
	//{
	//	a = n % m; // a = 90
	//	if (a == 0)
	//	{
	//		GCD = m;
	//	}
	//	else
	//	{
	//		b = m % a; // b = 42
	//		while (true)
	//		{
	//			c = b; //c = 42
	//			b = a % b;  // 6 = 90 % 42;

	//			if (b == 0)
	//			{
	//				GCD = c;
	//				break;
	//			}

	//			a = c; //a=42
	//		}
	//	}
	//}
	//else 
	//{
	//	a = m % n; // a = 90
	//	if (a == 0)
	//	{
	//		GCD = n;
	//	}
	//	else
	//	{
	//		b = n % a; // b = 42
	//		while (true)
	//		{
	//			c = b; //c = 42
	//			b = a % b;  // 6 = 90 % 42;

	//			if (b == 0)
	//			{
	//				GCD = c;
	//				break;
	//			}

	//			a = c; //a=42
	//		}
	//	}
	//}
#pragma endregion 

#pragma region ReferenceSolution
	//처음에는 두 수를 서로 나눠야함.
	int LargeInt = n;
	int SmallInt = m;
	if (m > n)
	{
		LargeInt = m;
		SmallInt = n;
	}

	while (true)
	{

		int r = LargeInt % SmallInt;

		if (r == 0)
		{
			//나머지가 0이 되면 직전의 나머지가 최대공약수
			GCD = SmallInt;
			break;
		}

		//0이 아닐 경우 이전의 나머지에다가 나눠줌.
		LargeInt = SmallInt;
		SmallInt = r;
	}
#pragma endregion

	LCM = m * n / GCD;

	answer.emplace_back(GCD);
	answer.emplace_back(LCM);

	return answer;
}

void main()
{

	vector<int> answer = solution(2, 5);

	for (auto& element : answer)
	{
		cout << element;
		cout << ",";
	}
	

	system("pause");
}