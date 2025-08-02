/* Descompunerea in factori primi a unui numar natural
 * Complexitate: O(sqrt(n)) - pe cazul cel mai defavorabil (n era prim)
 * Pe cazul general (n nu e prim), alrgoritmul este sub radicalic < O(sqrt(n))
 * 
 * Teorema fundamentala a aritmeticii:
 * "Oricare numar natural poate fi descompus in produs de factori primi"
 * 
 * n = 2^3 * 3^4 * 5^1 * 7^2 * 187001^1
 *  p: 2, 3, 4, 5, 6, 7, 8..., sqrt(187001)
 * 
 */ 
#include <iostream>
using namespace std;

void DescFact(int n) // < O(sqrt(n))
{
	cout << n << " = ";
	int p = 2, e = 0;
	
	while (p * p <= n)
	{
		e = 0;
		while (n % p == 0)
		{
			n /= p;
			e++;
		}
		
		if (e)
		{
			cout << p << '^' << e;
			if (n != 1)
				cout << " * ";
		}
		
		if (p == 2)
			p++;
		else
			p += 2;
	}
	
	if (n != 1)
		cout << n << "^" << 1;
}

int main()
{
	int n;
	cin >> n;
	DescFact(n);
}
