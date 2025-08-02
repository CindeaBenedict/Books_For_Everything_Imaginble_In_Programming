/* Deplasare (shiftare) la dreapta pe biti   (>>)
 * 
 * n >> k (n deplasat la dreapta cu k biti (pozitii)
 * Reprezentarea binara a lui n se deplaseaza la dreapta cu k pozitii
 * Numarul n pierde ultimii k biti
 *           B2 
 * Ex:  n = 10110110, k = 4
 *      n >> k = 1011
 * 
 * deplasare cu o pozitie inseamna impartire la 2
 * 
 * n >> k = n / 2^k
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
	B2(n >> k);  
	
//	n = n >> k;
	n >>= k;
	B2(n);
}





