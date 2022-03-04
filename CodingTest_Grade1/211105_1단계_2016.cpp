//Start Time	: 1617
//End Time		: 1640
//통과 유뮤		: 3트 통과

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string MySolution(int _Mon, int _Day) 
{
	string answer = "";
	
	//1m 1d = FRI
					//1	2     3    4   5  6		7 8 9 10 11 12
	int EndDay[12] = { 31, 29, 31, 30, 31, 30, 31,31,30,31,30,31 };
	string	szDay[7] = { "THU","FRI", "SAT","SUN", "MON", "TUE", "WED"};
	//이렇게 배열 자체를 1월 1일의 요일 보다 하루 전으로 시작하거나
	//string	szDay[7] = { "SUN", "MON", "TUE", "WED", "THU","FRI", "SAT" };

	int	iDaySum = 0;


	for (int i = 0; i < _Mon-1; ++i)
	{
		iDaySum += EndDay[i];
	}
	iDaySum += _Day;

	int iTemp = iDaySum % 7;
	
	answer = szDay[iDaySum % 7];
	//answer = szDay[(iDaySum+2) % 7];
	//1월 1일이 금요일임으로 4일을 더해주면 된다?
	//1월 1일이 월요일이면 더하기 0 화요일부터 1씩 더해주면서 시작 하면 됨.

	return answer;
}



void main()
{
	MySolution(1, 23);

	system("pause");
}