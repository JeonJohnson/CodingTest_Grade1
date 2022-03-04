//Start Time	: 1752
//End Time		: 1754
//통과 유뮤		: 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
	int answer = 0;

	for (int i = 0; i < (int)signs.size(); ++i)
	{
		signs[i] ? answer += absolutes[i] : answer -= absolutes[i];
	}

	return answer;
}

void main()
{


	system("pause");
}