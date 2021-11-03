//Start Time	: 1211
//End Time		: 1218
//통과 유뮤		: 1트 통

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> MySolution(vector<int> arr)
{
	vector<int> answer;
	
	int iTemp = -1;

	for (int i = 0; i < (int)arr.size(); ++i)
	{
		if (iTemp != arr[i])
		{
			iTemp = arr[i];
			answer.emplace_back(arr[i]);
		}
	}


	return answer;
}

void main()
{


	system("pause");
}