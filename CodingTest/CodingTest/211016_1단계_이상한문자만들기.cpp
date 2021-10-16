//Start Time	: 1710
//End Time		: 1736
//��� ����		: 2�� ���� �� ���

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string MySolution(string s) 
{
	//�ƽ�Ű �ڵ� ����
	//�ҹ��� a ~ z => 97~122
	//�빮�� A ~ Z => 65~90
	//�� ���� 32�� ���̰� ��.
	//�׷��ϱ� �ϴ� ��/�빮�� Ȯ���� �� �ڿ� 
	//���ָ� �ȴ�. �̸��̾�

	string answer = s;

	int iCurCharIndex = 0;

	for (int i = 0; i < (int)answer.length(); ++i)
	{
		if (answer[i] != ' ')
		{
			if (iCurCharIndex % 2 == 0)
			{//odd => to Upper alphabet -32
				if (answer[i] >= 'a' && answer[i] <= 'z')
				{
					answer[i] -= 32;
				}
			}
			else
			{//even => to lower alphabet +32
				if (answer[i] >= 'A' && answer[i] <= 'Z')
				{
					answer[i] += 32;
				}
			}

			++iCurCharIndex;
		}
		else 
		{
			iCurCharIndex = 0;
		}
	}

	return answer;
}

string OtherSolution(string s) {
	string answer = "";
	int nIndex = 1;
	for (int i = 0; i < s.size(); i++, nIndex++)
	{
		if (s[i] == ' ')
		{
			nIndex = 0;
			answer += " ";
		}
		else
		{
			// Ȧ�� ¦�� ���� �� �� 1�� and ��Ʈ�����
			// Ȧ���� ���̰� ¦���� ������ ���´�.
			// Ȧ���� �������� ����� ������ ������ 1�� ������ ������
			nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
			//toupper => �ҹ��ڸ� �빮�ڷ� �ٲ��ְ� �� �ƽ�Ű �ڵ� �� ��ȯ
			//tolower => �빮�ڸ� �ҹ��ڷ� �ٲ��ְ� �� �ƽ�Ű �ڵ� �� ��ȯ
		}
	}

	return answer;
}


void main()
{
	//solution("i wanna be a ur man");

	system("pause");
}