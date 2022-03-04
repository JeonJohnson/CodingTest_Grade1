//Start Time	: 04 00
//End Time		: 04 50
//통과 유뮤		: include 알고리즘 안먹혀서 lessSort만든다고 좀 늦음

// => 알고보니 include가 아닌 incldue라고 오타였음.
//첫 실행은 04 13이었음

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include <algorithm>


using namespace std;

vector<int> LessSort(vector<int> vec)
{
	vector<int> vecTemp;

	int iSize = (int)vec.size();

	while (vecTemp.size() < iSize)
	{
		vector<int>::iterator iter = vec.begin();
		int iMin = *iter;

		for (auto iterTemp = vec.begin(); iterTemp != vec.end(); ++iterTemp)
		{
			int asdf = (*iterTemp);

			if ((*iterTemp) < iMin)
			{
				iMin = *iterTemp;
				iter = iterTemp;
			}
		}

		vecTemp.emplace_back(iMin);
		vec.erase(iter);
	}

	return vecTemp;
}


vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;

	for (int i = 0; i < (int)commands.size(); ++i)
	{
		vector<int> vecTemp;

		int iStart = commands[i][0];
		int iEnd = commands[i][1];
		int iSel = commands[i][2];

		for (int k = commands[i][0]; k <= commands[i][1]; ++k)
		{
			vecTemp.emplace_back(array[k-1]);
		}
		
		//sort(vecTemp.begin(), vecTemp.end(), less<int>());
		vecTemp = LessSort(vecTemp);

		answer.emplace_back(vecTemp[commands[i][2] -1 ]);
	}
	
	
	return answer;
}


void main()
{

	vector<int> arr = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> com = { {2,5,3}, {4,4,1}, {1,7,3} };

	solution(arr, com);


	system("pause");
}