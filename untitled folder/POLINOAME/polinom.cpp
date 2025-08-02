/* ubb 2015 concurs
 * 
 * P(n) = a[0]*x^n + a[1]*x^(n-1) + ... + a[n-1]*x + a[n]
 * 
 * Pn = a[n]
 * p = 1
 * 
 *                                                      
 * 
 * 
 */ 
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Complexitate: O(n)
 * Nr operatiilor de inmultire: 2 * n
 */ 
double PIt1(int n, double a[], double x)
{
	double Px = a[n];
	double p = x;
	
	for (int i = n - 1; i >= 0; --i)
	{
		Px += a[i] * p;
		p *= x;
	}
	
	return Px;
}

/*
 * Complexitate: O(n)
 * Nr operatiilor de inmultire: n
 */ 
double PIt2(int n, double a[], double x)
{
	double P = a[0]; // polinom de grad 0
	for (int i = 1; i <= n; ++i)
		P = x * P + a[i];
	
	return P;
}
/*
 * Complexitate: O(n)
 * Nr operatiilor de inmultire: n
 */ 
double PRec(int n, double a[], double x)
{
	if (n == 0) return a[n];
	return x * PRec(n - 1, a, x) + a[n];
}

int main()
{
	int n = 3; // polinom de gradul 3
	double a[] = {40.24, -15.4656, -5.235, 6.233};
	double y  = - 11.1245;
	
	cout << fixed << setprecision(4) << PIt1(n, a, y) << '\n';
	cout << fixed << setprecision(4) << PIt2(n, a, y) << '\n';
	cout << fixed << setprecision(4) << PRec(n, a, y) << '\n';
}



