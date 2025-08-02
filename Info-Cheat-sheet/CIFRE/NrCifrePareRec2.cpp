#include <fstream>
#include <iostream>
using namespace std;
/*
 * n = 24
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
	if (n == 0) return 1;  // daca n era 0 de la inceput
	if (n < 10) // daca mai am o cifra
		return n % 2 == 0 ? 1 : 0;  // operator ternar / conditional
	
	return n % 2 == 0 ? NrCifre(n / 10) + 1 : NrCifre(n / 10);
}

int main()
{
	int n;
	cin >> n;
	cout << NrCifre(n);
}
