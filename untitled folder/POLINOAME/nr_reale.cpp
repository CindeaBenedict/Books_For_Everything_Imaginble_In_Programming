/* Afisarea numerelor reale
 * cu o precizie date.
 * 
 */ 
#include <iostream>
#include <iomanip>
using namespace std;

// float  - var pe 4 bytes
//          retine maxim 6 zecimale exacte

// double - var pe 8 bytes
//          retine 12 zecimale exacte (dublu fata de float)           

int main()
{
	float  f = 23.123456789876;
	double d = 23.123456789876;
	
//	cout << f;  // afiseaza in total 6 cifre!

	cout << fixed << setprecision(12) << f << '\n';
	cout << fixed << setprecision(12) << d << '\n';
	
//	cout << sizeof(float) << ' ' << sizeof(double) << '\n';  // returneaza nr de bytes
//	cout << sizeof(f) << ' ' << sizeof(d) << '\n';  // returneaza nr de bytes
}



