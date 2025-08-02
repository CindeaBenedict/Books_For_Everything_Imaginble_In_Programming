/* Combinari cu MEMOIZARE
 * Complexitate: O(n * n)
 * 
 * Formula recurenta a combinarilor:
 * Comb(n, k) = Comb(n - 1, k - 1) + Comb(n - 1, k)  
 *            = 1                                    daca k == 0 || k == n 
 */ 
#include <iostream>
using namespace std;

const int N = 201, MOD = 871021;
int C[N][N];
int cnt;

int Comb(int n, int k)
{
	cnt++;
	if (C[n][k]) return C[n][k];
	
	if (k == 0 || n == k)
		return C[n][k] = 1;
	
	return C[n][k] = (Comb(n - 1, k - 1) + Comb(n - 1, k)) % MOD;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << Comb(n, k) << '\n';
	cout << cnt;
	
}
