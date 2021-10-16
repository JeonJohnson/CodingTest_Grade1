//Start Time	: 1800
//End Time		: 
//통과 유뮤		: 못함. 약수 구하는 알고리즘 공부 해야함.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int solution(int n) 
{
	int answer = 0;
	vector<int> vDivisors;
	//약수 구하기
	//원래는 1부터 그 숫자까지 쭉 나눠보면서 나눠지는 숫자들을 구하는건데
	//ㅋㅋ 숫자 크면 클수록 답도 없음. 즉 O(n) 만큼 나옴. 답도 없지.

	//그래서 제곱근을 구한다음
	//제곱근의 약수를 구하는 것!
	//그럼 O(sqrt(n))만큼으로 줄어듬.
	//ex) 100가 들어왔을때

	//1. 정수의 제곱근 구하기
	//ex) 100의 제곱근은 10
	int iSqrtCount = (int)sqrt(n);

	for (int i = 1; i <= iSqrtCount; ++i)
	{//2. 1로 시작하는 이유는 0으로 나눌 수는 없자너

		if (n % i == 0)
		{//3. 약수 중 작은 수를 구하는것.
			//ex) 1로 나눌 경우 떨어짐.
			vDivisors.emplace_back(i);
			if (n / i != i)
			{//4. 약수 중 큰 수를 구하는 것.
			//위에서 들어간 그 수랑 짝지어질 다른 값을 찾는 부분.
				//ex)1로 나누면 나눠 떨어진다 했음. 그에 맞는 값은 100!
					//조건이 저런 이유는 10처럼 중복되는 값 없애기 위해서.
				vDivisors.emplace_back(n / i);
			}
		}
	}

	
	//지금 공부겸이니까 for문을 한번 더 돌려서 
	//더 해주는데
	//어차피 약수 구하면서 중복되는 수는 걸러주니까
	//바로 더해서 값 내면 될듯.
	for (auto& divisor : vDivisors)
	{
		answer += divisor;
	}
	
	int a = 0;

	return answer;
}

void main()
{
	solution(5);
	solution(12);
	solution(100);

	system("pause");
}