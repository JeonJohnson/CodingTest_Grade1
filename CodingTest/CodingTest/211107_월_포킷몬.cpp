//Start Time	: 16 52
//End Time		: 17 15
//통과 유뮤		: 1700실패 | 17 15 unique 구글링하고 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
	//1 1 2 4 5 5 6
	//1 2 4 5 6 5 6

	vector<int> vecTemp = nums;

	//vector에서 중복되는 값지우기.
	//algorithm의 unique 함수 사용하기.
	//unique 함수는 원소의들의 앞과 뒤를 비교하여
		//=> 앞과뒤만을 비교하기에 꼭 정렬을 하고나서 실행해야함.
	//중복되는 값(쓰래기값)들을 vector의 뒷부분으로 보낸다.
	//return 값으로 중복된(쓰래기)값이 들어가기 시작하는 
	//iterator을 반환함.
		//=> erase함수를 이용하여 지워줘야 함.

	//1. 일단 무적권 정렬!
	sort(vecTemp.begin(), vecTemp.end());
	//2. erase를 이용해 뒤로 빠져있는 중복된 값들을 지워주면 됨.
	vecTemp.erase(unique(vecTemp.begin(), vecTemp.end()), vecTemp.end());
	

	int iSelCount = (int)nums.size() / 2;

	if ((int)vecTemp.size() < iSelCount)
	{
		return (int)vecTemp.size();
	}
	else
	{
		return iSelCount;
	}
}

int OtherSolution(vector<int> nums) 
{
	unordered_set<int> s(nums.begin(), nums.end());

	//set이란?
	//균형 이진 트리로 구현 => 탐색이 빠름.
	//자동 정렬이 되는 노드 기반
	//중복된 값 불가능. 
		//=>중복된 값이 가지고 싶다면 multiset 사용
		//=> key값과 value값이 통합된 map 느낌.


	return min(nums.size() / 2, s.size());
}


void main()
{
	vector<int> vecTemp1 = { 3,1,2,3 };
	solution(vecTemp1);

	system("pause");
}