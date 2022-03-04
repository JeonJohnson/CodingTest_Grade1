//Start Time	: 1547
//End Time		:1554
//통과 유뮤		: 2트에 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

#define WIDTH 0
#define HEIGHT 1

int  MySolution(vector<vector<int>> sizes)
{
	int answer = 0;
	
	int iWidth = 0;
	int iHeight = 0;

	for (int i = 0; i < (int)sizes.size(); ++i)
	{
		if (sizes[i][HEIGHT] > sizes[i][WIDTH])
		{
			sizes[i][HEIGHT] ^=	sizes[i][WIDTH] ^=	sizes[i][HEIGHT] ^=	sizes[i][WIDTH];

		}

		if (sizes[i][WIDTH] >= iWidth)
		{
			iWidth = sizes[i][WIDTH];
		}

		if (sizes[i][HEIGHT] >= iHeight)
		{
			iHeight = sizes[i][HEIGHT];
		}
	}

	answer = iWidth * iHeight;

	return answer;
}

int OtherSolution(vector<vector<int>> sizes)
{
	int answer = 0;

	int w = 0, h = 0;
	for (int i = 0; i < sizes.size(); i++)
	{
		w = max(w, min(sizes[i][0], sizes[i][1])); //작은놈들 중에서 가장 큰놈
		h = max(h, max(sizes[i][0], sizes[i][1])); //그냥 젤큰놈
	}
	answer = w * h;

	return answer;
}

void main()
{


	system("pause");
}