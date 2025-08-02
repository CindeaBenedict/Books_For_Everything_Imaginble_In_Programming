/* Alg lui Euclid
 */ 
#include <iostream>
using namespace std;

int Cmmdc2(int a, int b);

int main()
{
	int a, b;
	cin >> a >> b;
	cout << Cmmdc2(a, b);
}

int Cmmdc2(int a, int b)
{
	if (b == 0) return a;
	return Cmmdc2(b, a % b);
}

