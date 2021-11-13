//Start Time	: 0505
//End Time		: 0520
//통과 유뮤		: 2트 성공

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(string s)
{
	int answer = 0;

	vector<string> Example = { "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	
	for (int i = 0; i < (int)Example.size(); ++i)
	{
		while (true)
		{
			if (s.find(Example[i]) == string::npos)
			{
				break;
			}

			int length = Example[i].length();
			
			//1번째 to_string 사용
			//s.replace(s.find(Example[i]), length, to_string(i));

			//2번째 아스키코드 이용해서 캐릭터형 
			char temp[255] = { (char)(i + 48) };
			s.replace(s.find(Example[i]), length, temp);


			
			
		}
	}

	answer = stoi(s);

	return answer;
}

void main()
{

	solution("one4seveneight");

	system("pause");
}