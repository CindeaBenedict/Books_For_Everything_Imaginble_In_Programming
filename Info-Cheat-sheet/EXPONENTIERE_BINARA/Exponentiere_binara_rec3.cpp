/* Ridicare la putere in timp logaritmic
 * Exponentiere Binara
 * Complexitate: O(log2(n))
 * 
 * Sa se calculeze x^n, unde n este f mare
 * 
 * x^n = x^(n / 2) * x^(n / 2)   daca n par
       = x^(n - 1) * x           daca n impar
 *     = 1                       daca n == 0
 * 
 
 * Pow(x, n) = Pow(x, n / 2) * Pow(x, n / 2)   daca n par
 *           = Pow(x, n - 1) * x               daca n impar
 *           = 1                               daca n == 0 
 */ 

#include <iostream>
using namespace std;

const int Mod = 457339;

int Pow(int x, int n) // O(log2(n)) - complexitate prea mare
{
	if (n == 0) return 1;
	int p = Pow(x, n / 2);
	
	if (n % 2 == 0)
		return p * p;
		
	return Pow(x, n - 1) * x;
}

int main()
{
	int x, n;
	cin >> x >> n;
	cout << Pow(x, n);
}




