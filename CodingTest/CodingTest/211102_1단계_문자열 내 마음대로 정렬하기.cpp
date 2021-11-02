//Start Time	: 0945
//End Time		: 1041
//통과 유뮤		: 2트 불통 후 구글링 했음. 불통.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int gIndex = 0;
//sort에 사용할 비교 함수에 인자가 필요할 경우 전역변수로 사용하자!


bool Compare(string s1, string s2)
{
	//if (s1[gIndex] < s2[gIndex])
	//{
	//	return true;
	//}
	//else if (s1[gIndex] == s2[gIndex])
	//{
	//	return s1 < s2;
	//}
	//이렇게 조건을 짜고 sort함수에 사용 invalid comparator 에러가 뜸.
	//이 에러는 strict weak ordering을 만족하지 못할 경우 뜸.
	//뭔소리냐면 
	//말 그대로 논리상 조건에 말이 안 맞는다는거임.
	//지금 저렇게 됐을 경우 s1[gIndex] > s2[gIndex]에 대한 예외 처리가 안되어있음.
	//return false에 대한 예외 처리가 없는거지...

	//if (s1[gIndex] < s2[gIndex])
	//{
	//	return true;
	//}
	//else if(s1[gIndex] > s2[gIndex])
	//{
	//	return false;
	//}
	//else if (s1[gIndex] == s2[gIndex])
	//{
	//	return s1 < s2;
	//}
	//그래서 이렇게 바꾸꺼나
	//아님 밑에 처럼 return 자체를 true, false로 할 수 있도록 하면 됨.

	
	//문자열을 대/소 비교가능.
	//s1<s2으로 하면 오름차순 정렬. (앞놈이 작은것이 true 이면 오름차순)
	//s1>s2으로 하면 내림차순 정렬. (앞놈이 큰것이 true이면 내림차순)

	if (s1[gIndex] == s2[gIndex])
	{
		return s1 < s2;
	}
	else
	{
		return s1[gIndex] < s2[gIndex];
	}

	//s1[gIndex] == s2[gIndex] ? s1 < s2 : s1[gIndex] < s2[gIndex];
	//로 줄일 수 있음.
}

vector<string> MySolution(vector<string> strings, int n) 
{
	vector<string> answer;
	answer = strings;
	gIndex = n;

#pragma region use the map container
	//map<int, string> mTemp;
	//for (auto& element : strings)
	//{
	//	if (mTemp.find(element[n]) == mTemp.end())
	//	{
	//		mTemp.emplace(element[n], element);
	//	}
	//}
	//for (auto& mapElement : mTemp)
	//{
	//	
	//	answer.emplace_back(mapElement.second);
	//}
#pragma endregion

	sort(answer.begin(), answer.end(), Compare);

	
	
	return answer;
}


void main()
{
	vector<string> vec = { "sun", "bed", "car" };

	MySolution(vec, 1);


	system("pause");
}