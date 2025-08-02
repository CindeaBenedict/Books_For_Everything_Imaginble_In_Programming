/* SAU (OR)- logic pe biti   (|)
 * 
 * Tabela de adevar
 * 
 * 1 | 1 = 1
 * 1 | 0 = 1
 * 0 | 1 = 1
 * 0 | 0 = 0
 * 
 * a = 1101011 |
 * b =  110101
 *     =======
 a | b 1111111
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
	int a, b;
	cin >> a >> b;
	
	B2(a); 
	B2(b); 
	B2(a | b); 
	
//	a = a | b;
	a |= b;  // operator de atribuire combinat
	B2(a);
}





