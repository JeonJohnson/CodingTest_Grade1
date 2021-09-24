//Start Time	: 1941
//End Time		: 
//Åë°ú À¯¹Â		: pass

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(long long n)
{
	double dSqrt = sqrt(n);

	if (dSqrt - (int)dSqrt > 0)
	{
		return -1;
	}
	else 
	{
		return pow(dSqrt + 1, 2);
	}
}


void main()
{
	solution(3);

	system("pause");
}