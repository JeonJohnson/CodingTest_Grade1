#include <iostream>
#include <stdio.h>
//1905 start
//1912 end
//pass
using namespace std;

void printRect(int _iRow, int _iCol)
{//Row 세로 개수 
	//Col 가로 개수

	for (int i = 0; i < _iCol; ++i)
	{
		for (int k = 0; k < _iRow; ++k)
		{
			cout << '*';
		}
		cout << '\n';
	}


}

void main()
{
	printRect(5, 3);



	system("pause");
}