/* Test Bit
 * testam bitul k al lui n => dorim sa vedem daca este setat (1) sau nesetat (0)
 * 
 *      k = 4
 * Ex:  n = 10110110 &
 *             10000      (1 << k)
 *          ========   
 *             10000  != 0 => bitul k este setat (1)
 * 
 *          k = 3
 * Ex:  n = 10110110 &
 *              1000      (1 << k)
 *          ========   
 *              0000  = 0 => bitul k este nesetat (0)
 
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
	
	if (n & (1 << k))
		cout << "bitul " << k << " este setat (1)";
	else
		cout << "bitul " << k << " este nesetat (0)";
		
}





