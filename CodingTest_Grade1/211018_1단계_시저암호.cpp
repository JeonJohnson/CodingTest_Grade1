//Start Time	: 1905
//End Time		: 1949
//통과 유뮤		: 2번 불통 후 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string MySolution(string s, int n)
{
	string answer = "";

	for (int i = 0; i < (int)s.length(); ++i)
	{
		if (s[i] != ' ')
		{
			int iTemp = s[i] + n;

			if (s[i] >= 'A' && s[i] <= 'Z' )
			{ //대문자
				if (iTemp > 'Z')
				{
					s[i] = iTemp - 26;					
					//바꾼 값이 아스키코드 범위 0~127을 넘어가 버리면
					//아예 문자열로 취급이 되지 않는건지 -26이 안먹음.
				}
				else 
				{ 
					s[i] += n;
				}
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{//소문자

				if (iTemp > 'z')
				{
					s[i] = iTemp - 26;
				}
				else 
				{
					s[i] += n;
				}
			}
		}
	}

	answer = s;
	return answer;
}

void main()
{

	MySolution("z",1);


	system("pause");
}