/* Sa se calculeze x^n, unde n este f mare
 * 
 * 
 */ 

#include <iostream>
using namespace std;

const int Mod = 457339;

int Pow(int x, int n) // O(n) - complexitate prea mare
{
	int p = 1;
	for (int i = 1; i <= n; ++i)
		p *= x;
	return p;
}

int main()
{
	int n;
	cin >> n;
	cout << Fact(n);
}




