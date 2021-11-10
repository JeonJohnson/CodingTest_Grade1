//Start Time	: 17 50
//End Time		: 17 51 
//통과 유뮤		: 17 51

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
	int answer = 0;

	for (int i = 0; i < (int)a.size(); ++i)
	{
		answer += a[i] * b[i];
	}

	return answer;
}

void main()
{


	system("pause");
}