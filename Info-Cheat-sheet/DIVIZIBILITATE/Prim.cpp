// Primalitatea unui numar natural
// Complexitate: O(sqrt(n))
#include <iostream>
using namespace std;

bool Prim(int n)
{
	// cazuri particulare
	if (n < 2)  return false;   // O(1)
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	
	// daca am ajuns aici, stim ca n este IMPAR
	for (int d = 3; d * d <= n; d += 2)
		if (n % d == 0)
			return false;
			
	return true;
}


int main()
{
	int n;
	cin >> n;
	if (Prim(n))
		cout << n << " este prim";
	else
		cout << n << " nu este prim";
}
