#include <fstream>
#include <iostream>
using namespace std;
/*
 * n = 2475
 * 
 * n = 0
 * s = 0;
 * 
 * while (n != 0)
 * {
 * 	s += n % 10;
 * 	n /= 10;
 * }
 * 
 */ 
int SumaCifrelor(int n)
{
	int sc = 0;
	while (n)
	{
		sc += n % 10;
		n /= 10;
	}
	return sc;
}

int main()
{
	int n;
	cin >> n;
	cout << SumaCifrelor(n);
}
