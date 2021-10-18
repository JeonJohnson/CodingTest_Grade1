#include <iostream>

#include <vector>

//2000 start
//2010 end
//
using namespace std;

vector<long long> solution(int _x, int _n)
{
	vector<long long> answer;

	for (int i = 0; i < _n; ++i)
	{
		answer.emplace_back(_x + (_x*i)) ;
	}

	return answer;
}

void main()
{

	vector<long long> asdf = solution(2, 5);

	for (int i = 0; i < asdf.size(); ++i)
	{
		cout << asdf.at(i) << endl;
	}


	system("pause");
}