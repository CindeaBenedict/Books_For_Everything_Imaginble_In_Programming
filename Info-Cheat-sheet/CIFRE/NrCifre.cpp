#include <fstream>
#include <iostream>
using namespace std;
/*
 * n = 2475
 * 
 * n = 0
 * s = 0;
 * int cnt = 0;
 * while (n != 0)
 * {
	cnt++;
 * 	n /= 10;
 * }
 * 
 */ 
int NrCifre(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	cout << NrCifre(n);
}
