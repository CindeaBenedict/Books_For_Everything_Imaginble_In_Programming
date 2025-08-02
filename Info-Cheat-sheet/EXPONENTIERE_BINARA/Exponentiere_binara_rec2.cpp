/* Ridicare la putere in timp logaritmic
 * Exponentiere Binara
 * Complexitate: O(log2(n))
 * 
 * Sa se calculeze x^n, unde n este f mare
 * 
 * x^n = (x^2)^(n / 2)        daca n par
 *     = (x^2)^(n / 2) * x    daca n impar
 *     = 1                    daca n == 0
 * 
 
 * Pow(x, n) = Pow(x * x, n / 2)      daca n par
 *           = Pow(x * x, n / 2) * x  daca n impar
 *           = 1                      daca n == 0 
 */ 

#include <iostream>
using namespace std;

const int Mod = 457339;

int Pow(int x, int n) // O(log2(n)) - complexitate prea mare
{
	if (n == 0) return 1;
	int p = Pow(x * x, n / 2);
	
	if (n % 2 == 1)
		p = p * x;
		
	return p;
}

int main()
{
	int x, n;
	cin >> x >> n;
	cout << Pow(x, n);
}




