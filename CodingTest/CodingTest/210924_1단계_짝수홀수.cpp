//Start Time	:
//End Time		:
//��� ����		:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int num)
{

	return num % 2 == 0 ? "Even" : "Odd";

	//return num & 1 ? "Odd" : "Even";
	//1) false = 0 �̰� �� �̿��� ������ �� true
	//=> Ȧ���� 2������ �ٲٸ� ~~~~ ~~~1�� ������ 1�� ����. 
		//�̰� 0001 �̳����� 1�� and ����(�� �� 1�� ��츸 1) ���� ���
		// 0001(2)  =>1(10)
		// 0011(2)  =>3(10)
		// 0001(2)	=> �� ���� ������ ���� ������ 0�̻��� ���� ����.
		//�׷��� ������ �����Ѱ�.

}

void main()
{
	cout << solution(3) << endl;
	
	

	system("pause");
}