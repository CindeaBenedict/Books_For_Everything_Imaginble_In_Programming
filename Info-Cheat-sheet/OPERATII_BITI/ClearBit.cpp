/* Clear Bit
 * Resetam bitul k adica il facem 0
 * 
 *      k = 4
 * Ex:  n = 1010110 ^
 *            10000
 *          =======
            1000110  
            
            // Atentie, bitul k trebuie mai intsi testat !
*  Ex:  n = 1000110 ^
 *            10000
 *          =======
            1010110  
 
 */ 
#include <iostream>
using namespace std;

// afiseaza cifrele lui n in baza b
void B2(int n)
{
	if (n == 0)	return;

	B2(n / 2);
	cout << n % 2;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	B2(n);  cout << '\n';     
	
	if (n & (1 << k)) // daca bitul k este 1
		//n = n ^ (1 << k);
		n ^= 1 << k;
		
	B2(n);
}





