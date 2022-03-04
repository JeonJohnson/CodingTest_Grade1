//Start Time	: 1958
//중간에 치킨 고민하다 2020 시작
//End Time		: 2037
//통과 유뮤		: 1번 오답후 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;



vector<int> solution(long long n)
{
	vector<int> answer;
	
	string szTemp = to_string(n);
	reverse(szTemp.begin(), szTemp.end());
	//sort(szTemp.begin(), szTemp.end(), );
	
	for (int i = 0; i < (int)szTemp.length(); ++i)
	{
		char szIntchar[255] = { szTemp[i] };

		answer.emplace_back(atoi(szIntchar));
	}



	return answer;
}


vector<int> OtherSolution(long long n)
{
	vector<int> answer;

	while (n)
	{
		//1) 10의 나머지 구하기
		answer.emplace_back(n % 10);
		// 이러면 마지막 자리수만 구할 수 있음.

		//2) 10으로 나눠벌이기
		n /= 10;
		//방금 계산한 마지막 자리수 없애버리는 것.

	}
	return answer;
}


void main()
{
	solution(98765);
	//cout << solution(12345) << endl;
	system("pause");
}