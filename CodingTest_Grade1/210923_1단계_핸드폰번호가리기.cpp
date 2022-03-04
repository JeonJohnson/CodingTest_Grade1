//Start Time	: 2133
//End Time		: 2138
//통과 유뮤		: pass

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string _phoneNumber)
{
	string answer = _phoneNumber;

	for (int i = 0; i < answer.size()-4; ++i)
	{
		answer[i] = '*';
	}


	return answer;
}

void main()
{
	string answer = solution("66759121");

	cout << answer << endl;

	system("pause");
	
}