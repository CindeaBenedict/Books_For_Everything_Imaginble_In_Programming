/* Doi la puterea n
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
	
	cout << (1LL << n);
	
	B2(1LL << n);       
	
}





