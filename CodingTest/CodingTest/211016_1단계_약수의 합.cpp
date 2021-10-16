//Start Time	: 1800
//End Time		: 
//��� ����		: ����. ��� ���ϴ� �˰��� ���� �ؾ���.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int solution(int n) 
{
	int answer = 0;
	vector<int> vDivisors;
	//��� ���ϱ�
	//������ 1���� �� ���ڱ��� �� �������鼭 �������� ���ڵ��� ���ϴ°ǵ�
	//���� ���� ũ�� Ŭ���� �䵵 ����. �� O(n) ��ŭ ����. �䵵 ����.

	//�׷��� �������� ���Ѵ���
	//�������� ����� ���ϴ� ��!
	//�׷� O(sqrt(n))��ŭ���� �پ��.
	//ex) 100�� ��������

	//1. ������ ������ ���ϱ�
	//ex) 100�� �������� 10
	int iSqrtCount = (int)sqrt(n);

	for (int i = 1; i <= iSqrtCount; ++i)
	{//2. 1�� �����ϴ� ������ 0���� ���� ���� ���ڳ�

		if (n % i == 0)
		{//3. ��� �� ���� ���� ���ϴ°�.
			//ex) 1�� ���� ��� ������.
			vDivisors.emplace_back(i);
			if (n / i != i)
			{//4. ��� �� ū ���� ���ϴ� ��.
			//������ �� �� ���� ¦������ �ٸ� ���� ã�� �κ�.
				//ex)1�� ������ ���� �������� ����. �׿� �´� ���� 100!
					//������ ���� ������ 10ó�� �ߺ��Ǵ� �� ���ֱ� ���ؼ�.
				vDivisors.emplace_back(n / i);
			}
		}
	}

	
	//���� ���ΰ��̴ϱ� for���� �ѹ� �� ������ 
	//�� ���ִµ�
	//������ ��� ���ϸ鼭 �ߺ��Ǵ� ���� �ɷ��ִϱ�
	//�ٷ� ���ؼ� �� ���� �ɵ�.
	for (auto& divisor : vDivisors)
	{
		answer += divisor;
	}
	
	int a = 0;

	return answer;
}

void main()
{
	solution(5);
	solution(12);
	solution(100);

	system("pause");
}