//Start Time	: 0710
//End Time		: 0725
//��� ����		: pass

#include <iostream>
#include <vector>

using namespace std;

int solution(int num)
{
	int answer = 0;

	long long llNum = num;
	//���ϱ� 3�� ���ٺ��� ū ���� ���� ���� �����÷� ��ħ

	while (llNum != 1)
	{
		if (llNum % 2 == 0)
		{//¦��
			llNum /= 2;
		}
		else 
		{//Ȧ�� 
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