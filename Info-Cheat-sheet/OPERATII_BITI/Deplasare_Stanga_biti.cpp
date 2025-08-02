/* Deplasare (shiftare) la stanga pe biti   (<<)
 * 
 * n << k (n deplasat la stanga cu k biti (pozitii)
 * Reprezentarea binara a lui n se deplaseaza la stanga cu k pozitii
 * si la finalul reprezentarii se adauga k biti de 0
 *           B2 
 * Ex:  n = 1011, k = 3
 *      n << k = 1011000
 * 
 * deplasare cu o pozitie inseamna inmultire cu 2
 * 
 * n << k = n * 2^k
 */ 
#include <iostream>
using namespace std;

// afiseaza cifrele lui n in baza b
void B2(int n)
{
	if (n == 0) 
	{
		cout << '\n';
		return;
	}
	B2(n / 2);
	cout << n % 2;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	B2(n);       
	B2(n << k);  
	
//	n = n << k;
	n <<= k;
	B2(n);
}





