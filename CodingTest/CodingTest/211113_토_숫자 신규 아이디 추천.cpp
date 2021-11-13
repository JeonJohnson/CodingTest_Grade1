//Start Time	: 0600
//End Time		: 0640
//통과 유뮤		: 0623 1트 실패 

//1트 실패 : 5, 8, 12, 13, 15, 20, 21, 22, 25
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string new_id)
{
	string answer = "";

	for (int i = 0; i < new_id.length(); ++i)
	{
		char chTemp = new_id[i];
		new_id[i] = tolower(new_id[i]);

		if ((new_id[i] >= 'a' && new_id[i] <= 'z')
			|| (new_id[i] >= '0' && new_id[i] <= '9')
			|| (new_id[i] == '-')
			|| (new_id[i] == '_')
			|| (new_id[i] == '.'))
		{
			if (new_id[i] == '.')
			{
				if (i != 0 && new_id[i-1] != '.' && i != new_id.length() -1 )
				{
					if (answer.length() != 0
						&& answer.back() != '.')
					{
						answer += new_id[i];
					}
					
				}
			}		
			else 
			{
				answer += new_id[i];
			}
		}

		if (answer.length() >= 15)
		{
			break;
		}

	}

	if (answer.back() == '.')
	{
		answer.pop_back();
	}


	if (answer == "")
	{
		answer += 'a';
	}

	if (answer.length() <= 2)
	{
		while (answer.length() < 3)
		{
			answer += answer.back();
		}
		
	}

	

	return answer;
}


string OtherSolution(string new_id) 
{
	for (char& ch : new_id)
	{
		if ('A' <= ch && ch <= 'Z')
		{
			ch |= 32;
		}
	}

	string ret;

	for (char& ch : new_id) 
	{
		if ('a' <= ch && ch <= 'z' 
			||'0' <= ch && ch <= '9' 
			|| strchr("-_.", ch))
		{//strchr(const char* A, int c)
			//A문자열에 c가 있는지 없는지 확인 함.
			//오히려 이걸 반대로 해서 있는지 없는지 확인하네 기똥차노
			ret += ch;
		}
	}

	new_id = ret;

	ret.clear();

	for (char& ch : new_id) 
	{
		if (!ret.empty() && ret.back() == '.' && ch == '.')
		{
			continue;
		}
		ret += ch;
	}

	if (ret.front() == '.') ret.erase(ret.begin());
	if (ret.back() == '.') ret.pop_back();

	if (ret.empty()) ret = "a";
	if (ret.size() >= 16) ret = ret.substr(0, 15);
	if (ret.back() == '.') ret.pop_back();
	while (ret.size() <= 2) ret += ret.back();

	return ret;
}

void main()
{
	solution("./././././abcd/././././.");

	system("pause");
}