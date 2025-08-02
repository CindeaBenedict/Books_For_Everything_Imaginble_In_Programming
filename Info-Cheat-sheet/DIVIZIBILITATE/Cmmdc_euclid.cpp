/* Cmmdc a doua numere naturale
 * Metoda impartirilor (repetate)
 * Alg. lui Euclid
 * 
 * a = b * cat + rest
 * 
 * 
 * Cmmdc(a, b) = Cmmdc(b, a % b)   daca b != 0
 *             = a                 daca b = 0
 * 
 * a   b    rest
 * 16  12   4 
 * 12   4   0
 *  4   0
 * =======
 * cmmdc = 4 
 * 

 *
 
 */ 
#include <iostream>
using namespace std;

              
int Cmmdc2(int a, int b)
{
	int rest;
	while (b)
	{
		rest = a % b;
		a = b;
		b = rest;
	}
	
	return a;
}

int main()
{
	int x, y;
	cin >> x >> y;
	
	cout << Cmmdc2(x, y);
}
