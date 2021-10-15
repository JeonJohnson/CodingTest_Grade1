//Start Time	: 2325
//End Time		:
//��� ����		:

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
		//�ƽ�Ű �ڵ��� ��������
		// '0' = 48
		// '1' = 49
		// '2' = 50
		//... ...
		// '9' = 57
		//ó�� 48�� ������ 1�� �þ���� - '0' �ϸ� �� �������� ���´�.
	}

	return answer;
}

int OtherSoluition_2(int n)
{
	int answer = 0;
	//��� ���� �� �ڸ��� ���� ���ϴ� ��.
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