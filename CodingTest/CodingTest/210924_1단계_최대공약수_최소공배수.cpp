//Start Time	: 0730
//End Time		: 0808
//��� ����		: none

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, int m)
{
	//�ִ�����(GCD) ���ϴ� �� -> ���μ� ���� �� ����� ���μ��� ���ϸ� ��.
		//or ��Ŭ���� ȣ���� ��� => ū������ �������� ���� �������� ���� ������ ��
		//�򿡼� �������� ������ �� ������ �� ���� �ݺ�.
	//�ּҰ����(LCM) ���ϴ� �� -> ���μ� ���� �� ��� ���μ��� ���ϸ� ��.
		//or �μ��� ���� �ִ������� ���� ��

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
	//ó������ �� ���� ���� ��������.
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
			//�������� 0�� �Ǹ� ������ �������� �ִ�����
			GCD = SmallInt;
			break;
		}

		//0�� �ƴ� ��� ������ ���������ٰ� ������.
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