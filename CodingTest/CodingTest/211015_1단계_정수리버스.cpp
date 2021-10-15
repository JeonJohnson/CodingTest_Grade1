//Start Time	: 1958
//�߰��� ġŲ ����ϴ� 2020 ����
//End Time		: 2037
//��� ����		: 1�� ������ ���

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;



vector<int> solution(long long n)
{
	vector<int> answer;
	
	string szTemp = to_string(n);
	reverse(szTemp.begin(), szTemp.end());
	//sort(szTemp.begin(), szTemp.end(), );
	
	for (int i = 0; i < (int)szTemp.length(); ++i)
	{
		char szIntchar[255] = { szTemp[i] };

		answer.emplace_back(atoi(szIntchar));
	}



	return answer;
}


vector<int> OtherSolution(long long n)
{
	vector<int> answer;

	while (n)
	{
		//1) 10�� ������ ���ϱ�
		answer.emplace_back(n % 10);
		// �̷��� ������ �ڸ����� ���� �� ����.

		//2) 10���� �������̱�
		n /= 10;
		//��� ����� ������ �ڸ��� ���ֹ����� ��.

	}
	return answer;
}


void main()
{
	solution(98765);
	//cout << solution(12345) << endl;
	system("pause");
}