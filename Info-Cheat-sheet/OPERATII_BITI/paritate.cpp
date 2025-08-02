/* Testarea paritatii unui nr natural
 * 
 * n  = 101011 &
 *           1
 *      ======   
 *           1  => n impar
 * 
 * n  = 101010 &
 *           1
 *      ======   
 *           0  => n par
 * 
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
	int n;
	cin >> n;
	
	B2(n); 
	cout << '\n';
	if (n & 1) // if (n % 2 == 1)
		cout << n << " impar";
	else
		cout << n << " par";
		 
}




