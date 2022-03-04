//Start Time	: 2140
//pause time	: 2202
//puase canceltime : 2214
//End Time		: 2219 (25분)
//통과 유뮤		: pass

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(int x)
{
#pragma region mySolution
	//string szTemp = to_string(x);

	//int iLen = szTemp.size();

	//int iSum = 0;

	//for (int i = 0; i < iLen; ++i)
	//{
	//	iSum += szTemp[i] - 48;
	//}

	//return x % iSum == 0 ? true : false;
#pragma  endregion 

#pragma region OtherSolution
	int iSum = 0;
	int iTemp = x;

	while (iTemp > 0)
	{
		iSum += iTemp % 10;
		iTemp /= 10;
	}

	return x%iSum == 0;

#pragma endregion

}

void main()
{

	cout << solution(11) << endl;
	cout << solution(12) << endl;
	cout << solution(18) << endl;
	cout << solution(27) << endl;
	cout << solution(32) << endl;
	cout << solution(200) << endl;

	system("pause");
}