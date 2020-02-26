#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool checkValue(int a) {
	return a & (1 << (sizeof(a) * 8 - 1));
}

void sum(int a, int b, int & suma)
{
	suma = a;
	while (b != 0)
	{
		suma = -~ suma;
		b = ~- b;
	}
}

bool lessThan(int x, int y)
{
	if (checkValue(x) && !checkValue(y))
		return true;
	else if (!checkValue(x) && checkValue(y))
		return false;
	for (int i = sizeof(x) * 8 - 1; i >= 0; i--)
	{
		int z = 1 << i;
		if ((x & z) != (y & z))
			if ((x & z) && !checkValue(x))
				return false;
			else
				return true;
	}
}


