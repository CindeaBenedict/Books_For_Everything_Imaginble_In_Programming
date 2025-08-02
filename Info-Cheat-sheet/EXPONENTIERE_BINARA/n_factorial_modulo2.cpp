/* Sa se calculeze n! mod Mod
 */ 

#include <iostream>
using namespace std;

const int Mod = 457339;

int Fact(int n)
{
	int f = 1;
	for (int i = 1; i <= n; ++i)
		f = ((long long)f * i) % Mod;
	return f;
}

int main()
{
	int n;
	cin >> n;
	cout << Fact(n);
}




