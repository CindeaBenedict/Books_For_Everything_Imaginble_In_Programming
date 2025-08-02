/* Cmmmc a doua numere naturale
 * 
 * cmmmc(a, b) = a * b / Cmmdc2(a, b)

 */ 
#include <iostream>
using namespace std;

            
int Cmmdc2(int a, int b);
int Cmmmc2(int a, int b);


int main()
{
	int x, y;
	cin >> x >> y;
	
	cout << Cmmmc2(x, y);
}

int Cmmmc2(int a, int b)
{
	return a * b / Cmmdc2(a, b);
}

int Cmmdc2(int a, int b)
{
	if (b == 0) return a;
	return Cmmdc2(b, a % b);
}
