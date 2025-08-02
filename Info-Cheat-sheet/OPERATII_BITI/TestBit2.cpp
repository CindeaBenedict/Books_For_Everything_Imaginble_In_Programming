/* Test Bit
 * testam bitul k al lui n => dorim sa vedem daca este setat (1) sau nesetat (0)
 * 
 *      k = 4
 * Ex:  n = 10110110 
 * 
 * n >> k = 1011 &
 *             1
 *          ====
 *             1  => bitul k este setat (1)  
 * 
 *          k = 3
 * Ex:  n = 10110110 
 * 
 * n >> k = 10110 &
 *              1
 *          =====
 *              0 => bitul k este neseat (0)  
 
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
	
	if ((n >> k) & 1)
		cout << "bitul " << k << " este setat (1)";
	else
		cout << "bitul " << k << " este nesetat (0)";
}





