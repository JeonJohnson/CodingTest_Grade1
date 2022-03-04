//Start Time	:
//End Time		:
//통과 유뮤		:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int num)
{

	return num % 2 == 0 ? "Even" : "Odd";

	//return num & 1 ? "Odd" : "Even";
	//1) false = 0 이고 그 이외의 값들은 다 true
	//=> 홀수를 2진수로 바꾸면 ~~~~ ~~~1로 무적권 1로 끝남. 
		//이걸 0001 이나오는 1과 and 연산(둘 다 1일 경우만 1) 했을 경우
		// 0001(2)  =>1(10)
		// 0011(2)  =>3(10)
		// 0001(2)	=> 뭔 값이 나오던 간에 무적권 0이상의 값이 나옴.
		//그래서 저렇게 가능한거.

}

void main()
{
	cout << solution(3) << endl;
	
	

	system("pause");
}