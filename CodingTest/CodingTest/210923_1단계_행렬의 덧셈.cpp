//2117 start
//2128 end
//pass

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
							vector<vector<int>> arr2)
{
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); ++i)
	{
		vector<int> vTemp;
		for (int k = 0; k < arr1[i].size(); ++k)
		{
			int temp = arr1[i][k] + arr2[i][k];
			vTemp.emplace_back(temp);
		}
		answer.emplace_back(vTemp);
	}

	return answer;
}

void main()
{
	vector<vector<int>> arr1 = { {1,2}, {2,3} };
	vector<vector<int>> arr2 = { { 3,4 },{ 5,6 } };
	vector<vector<int>> answer = solution(arr1, arr2);

	
	for (int i = 0; i < answer.size(); ++i)
	{
		for (int k = 0; k < answer[i].size(); ++k)
		{
			cout << answer[i][k];
		}
		cout << "\n";
	}


	system("pause");
	

}