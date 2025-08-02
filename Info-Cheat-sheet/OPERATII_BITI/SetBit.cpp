/* Set Bit
 * Setam bitul k al lui n, adica il facem 1
 * 
 *      k = 3
 * Ex:  n = 1010110 | 
 *             1000
 *          =======
            1011110  
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
	
	B2(n);  
	cout << '\n';     
	
//	n = n | (1 << k);
	n |= 1 << k;
	
	B2(n);
}





