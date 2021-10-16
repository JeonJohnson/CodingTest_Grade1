//Start Time	: 1710
//End Time		: 1736
//통과 유뮤		: 2번 불통 후 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string MySolution(string s) 
{
	//아스키 코드 기준
	//소문자 a ~ z => 97~122
	//대문자 A ~ Z => 65~90
	//즉 둘은 32씩 차이가 남.
	//그러니까 일단 소/대문자 확인을 한 뒤에 
	//빼주면 된다. 이말이야

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
			// 홀수 짝수 구분 할 때 1과 and 비트연산시
			// 홀수는 참이고 짝수는 거짓이 나온다.
			// 홀수는 이진수로 변경시 무적권 마지막 1이 나오기 때문에
			nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
			//toupper => 소문자를 대문자로 바꿔주고 그 아스키 코드 값 반환
			//tolower => 대문자를 소문자로 바꿔주고 그 아스키 코드 값 반환
		}
	}

	return answer;
}


void main()
{
	//solution("i wanna be a ur man");

	system("pause");
}