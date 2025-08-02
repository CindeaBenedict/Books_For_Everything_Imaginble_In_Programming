/* Combinari cu descompunere in factori primi
 * Complexitate: O(n * sqrt(n))
 * 
 * Obs: Merge si daca MOD < n
 * 
 * 
 * Comb(n, k) = n! / k! * (n - k)!
 *            = (n - k + 1) * (n - k + 2) * ... * n / 
 *               1 * 2 * 3 * ... * k
 * Ex  
 * Comb(n, k) = 2^7 * 3^6 * 5^11 * 7^3 /
 *              2^4 * 3^4 * 5^7 * 7^2
 * 
 *            = 2^3 * 3^2 * 5^4 * 7^1
 */ 
#include <iostream>
using namespace std;

const int N = 100001, MOD = 871021;


int pw[N];   // pw[p] = puterea la care apare nr prim p in desomp in fact primi

void DescompNumarator(int n) // O(sqrt(n))
{
	int d = 2, e = 0;
	while (n != 1)
	{
		e = 0;
		while (n % d == 0)
		{
			n /= d;
			e++;
		}
		
		if (e)
			pw[d] += e;
		d++;
		if (d * d > n) 
			d = n;
	}
}

void DescompNumitor(int n)
{
	int d = 2, e = 0;
	while (n != 1)
	{
		e = 0;
		while (n % d == 0)
		{
			n /= d;
			e++;
		}
		
		if (e)
			pw[d] -= e;
		d++;
		if (d * d > n) 
			d = n;
	}
}

int Comb(int n, int k) // O(n * sqrt(n))
{
	// desc in factori primi numaratorul
	for (int i = n - k + 1; i <= n; ++i)
		DescompNumarator(i);
		
	// desc in fact primi numitorul
	for (int i = 2; i <= k; ++i)
		DescompNumitor(i);
	
	int cmb = 1;
	for (int p = 2; p <= n; ++p)
		while (pw[p]--)
			cmb = (1LL * cmb * p) % MOD;
			
	return cmb;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << Comb(n, k);
}


