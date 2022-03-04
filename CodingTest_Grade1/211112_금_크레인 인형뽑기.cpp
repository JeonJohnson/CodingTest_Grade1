//Start Time	: 0935
//End Time		: 1015 
//통과 유뮤		: 40분

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	//0,0,0,0,0
	//0,0,1,0,3
	//0,2,5,0,1
	//4,2,4,4,2
	//3,5,1,3,1

	//1,5,3,5,1,2,1,4
	int answer = 0;

	vector<int> vecBasket;

	//1. 세로줄을 새로 담을 놈 만들기
	vector<vector<int>> vecGrid;
	//0,0,0,4,3
	//0,0,2,2,5
	//0,1,5,4,1
	//0,0,0,4,3
	//0,3,1,2,1
	//=>근데 굳이 이렇게 안해도 됨.

	for (int i = 0; i < (int)board.size(); ++i)
	{
		vector<int> vecTemp;
		for (int k = 0; k < (int)board[i].size(); ++k)
		{
			if (board[k][i] != 0)
			{
				vecTemp.emplace_back(board[k][i]);
			}
		}

		vecGrid.emplace_back(vecTemp);
	}

	int iPast = -2;
	int iCur = -1;

	for (int i = 0; i < (int)moves.size(); ++i)
	{
		if (vecGrid[moves[i] - 1].size() > 0)
		{

			iPast = iCur;
			iCur = vecGrid[moves[i] - 1].front();

			if (iCur == iPast)
			{
				answer += 2;
				vecBasket.pop_back();

				if (vecBasket.size() > 0)
				{
					iCur = vecBasket.back();
				}
				else
				{
					iPast = -2;
				}

			}
			else
			{
				vecBasket.emplace_back(iCur);
				
			}

			vecGrid[moves[i] - 1].erase(vecGrid[moves[i] - 1].begin());
		}
	}


	return answer;
}

void main()
{
	vector<vector<int>> board = { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} };
	vector<int> move = { 1,5,3,5, 1,2,1,4 };

	solution(board, move);

	
	
	system("pause");
}