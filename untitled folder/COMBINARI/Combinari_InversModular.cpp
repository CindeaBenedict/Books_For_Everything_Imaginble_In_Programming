/* Combinari cu Invers Modular
 * Complexitate: O(n)
 * 
 * 
 * Comb(n, k) = n! / k! * (n - k)!
 * 
 * (a / b) % MOD != (a % MOD) / (b % MOD) - gresit
 * 
 * Mica Teorema a lui Fermat:
 * 
 * Daca MOD este un numar PRIM, atunci numim
 * inversul modular al lui x valoarea:
 * 
 * InvMod(b) = (1 / b) % MOD = Pow(b, MOD - 2) % MOD
 * 
 * Ex:  (a / b) % MOD = (a * Pow(b, MOD - 2)) % MOD
 * 
 * 
 * Notatie:
 * I[k] = inversul modular al lui k!
 * I[n - k] = inversul modular al lui (n - k)!
 * F[n] = n! % MOD
 * 
 * 
 * ATENTIE!
 * Se aplica cand MOD > n
 */ 
#include <iostream>
using namespace std;

const int N = 100001, MOD = 871021;
int F[N];   // n! % MOD
int I[N];   // I[x] = inversul modular al lui x!

int Pow(int x, int n)
{
	int r = 1;
	while (n)
	{
		if (n & 1) 
			r = (1LL * r * x) % MOD;
		x = (1LL * x * x) % MOD;
		n >>= 1;
	}
	
	return r;
}

void PreCalc(int n, int k) // O(n)
{
	F[0] = I[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		F[i] = (1LL * i * F[i - 1]) % MOD;
	//	I[i] = Pow(F[i], MOD - 2);  // O(log2(MOD))
	}
	
	I[k] = Pow(F[k], MOD - 2); 
	I[n - k] = Pow(F[n - k], MOD - 2);
}

int Comb(int n, int k)
{
	return ((1LL * F[n] * I[k]) % MOD * I[n - k]) % MOD;
}

int main()
{
	int n, k;
	cin >> n >> k;
	PreCalc(n, k);
	cout << Comb(n, k);
}


