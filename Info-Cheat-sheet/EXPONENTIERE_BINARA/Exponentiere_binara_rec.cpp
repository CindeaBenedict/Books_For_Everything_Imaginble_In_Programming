/* Ridicare la putere in timp logaritmic
 * Exponentiere Binara
 * Complexitate: O(log2(n))
 * 
 * Sa se calculeze x^n, unde n este f mare
 * 
 * x^n = x^(n / 2) * x^(n / 2)        daca n par
 *     = x^(n / 2) * x^(n / 2) * x    daca n impar
 *     = 1                            daca n == 0
 * 
 *                    P      *    P 
 * Pow(x, n) = Pow(x, n / 2) * Pow(x, n / 2)      daca n par
 *           = Pow(x, n / 2) * Pow(x, n / 2) * x  daca n impar
 *           = 1                                  daca n == 0 
 */ 

#include <iostream>
using namespace std;

const int Mod = 457339;

int Pow(int x, int n) // O(log2(n)) - complexitate prea mare
{
	if (n == 0) return 1;
	int p = Pow(x, n / 2);
	
	p = (1LL * p * p) % Mod;
	if (n % 2 == 1)
		p = (1LL * p * x) % Mod;
		
	return p;
}

int main()
{
	int x, n;
	cin >> x >> n;
	cout << Pow(x, n);
}




