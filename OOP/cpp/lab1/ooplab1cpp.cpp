#include <iostream>
using namespace std;
#include "Header.h"
#include <vector>

int main()
{
	int a, b;
	cin >> a >> b;
	int suma = 0;
	sum(a, b, suma);
	cout << suma;
	cout << endl;
	cout << lessThan(-6,1);
	//cout << lessThan(a, b);
}