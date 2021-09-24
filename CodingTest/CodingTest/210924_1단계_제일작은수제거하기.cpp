//Start Time	: 1913
//End Time		: 1930
//Åë°ú À¯¹Â		: pass

#include <iostream>
#include <vector>

using namespace std;


vector<int> solution(vector<int> arr)
{
	vector<int> answer = arr;

	if (answer.size() <= 1)
	{
		answer.clear();
		answer.emplace_back(-1);
		return answer;
	}

	int iLeastInt = answer[0];
	vector<int>::iterator iLeastIndex = answer.begin();

	for (auto _iter = answer.begin()+1; _iter != answer.end(); ++_iter)
	{
		if (iLeastInt > (*_iter))
		{
			iLeastInt = *_iter;
			iLeastIndex = _iter;
		}
	}

	answer.erase(iLeastIndex);

	return answer;
}

void main()
{
	auto temp = solution(vector<int>{10});

	for (auto element : temp)
	{
		cout << element << endl;
	}


	system("pause");
}