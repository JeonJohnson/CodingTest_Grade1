//Start Time	: 16 52
//End Time		: 17 15
//통과 유뮤		: 1659효율성 실패 | 1715 성공

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	for (int i = 0; i < (int)completion.size(); ++i) //O n
	{
		auto iter = find(participant.begin(), participant.end(), completion[i]); //O n 

		if (iter != participant.end())
		{
			participant.erase(iter);

			if (participant.size() == 1)
			{
				break;
			}
		}
	}

	answer = participant.front();

	return answer;

	//=> O n^2 복잡도
}

string solution2(vector<string> participant, vector<string> completion)
{
	string answer = "";

	//정렬하고 각각 비교하다가 다른거 참가자에서 다른 놈이 나오면 그놈이 범인!
	sort(participant.begin(), participant.end()); //log n
	sort(completion.begin(), completion.end()); //log n
	
	for (int i = 0; i < completion.size(); ++i) //O n 
	{
		if (participant[i] != completion[i])
		{
			return participant[i];
		}
	}

	//만약 서로 다 같다면? 마지막 놈 
		//=> completion 이 무적권 participant보다 1작으니까 간으할듯
	return participant.back();

	// log n + log n + n 
	// n^2 보단 작음. 저거 다 곱하기 해야 n^2나오니까
}


void main()
{
	vector<string> parti = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> com = { "josipa", "filipa", "marina", "nikola" };

	solution2(parti, com);

	system("pause");
}