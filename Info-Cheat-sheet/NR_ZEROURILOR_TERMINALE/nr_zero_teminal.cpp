/*  Se da un sir a[] cu n nr naturale.
 *  Sa se det nr de zerouri terminale ale produsului:
 *  n <= 100000, a[i] <= 1 miliard
 *  P = a[1] * a[2] * ... * a[n]
 * 
 * Ex:  a = 2^3 * 5^4 * C1
 *      b = 2^4 * 5^6 * C2
 * 
 *     a * b = 2^3 * 5^4 * C1 * 2^4 * 5^6 * C2
 *           = 2^7 * 5^10 * C 
 * 
 * 		nr_Zerouri(a * b) = min(7, 10) = 7
*/
#include <iostream>
using namespace std;

const int N = 100000;
int a[N], n;

int main()
{
	// citeste sir
	
	int exp2 = 0, exp5 = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		while (a[i] % 2 == 0)
		{
			exp2++;
			a[i] /= 2;
		}
		
		while (a[i] % 5 == 0)
		{
			exp5++;
			a[i] /= 5;
		}
	}
	
	cout << min(exp2, exp5);
	
}
