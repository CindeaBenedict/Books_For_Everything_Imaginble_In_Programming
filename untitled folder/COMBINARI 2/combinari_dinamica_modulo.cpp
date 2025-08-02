/* Combinari cu programare dinamica
 * Complexitate: O(n * n)
 * 
 * Formula recurenta a combinarilor:
 * Comb(n, k) = Comb(n - 1, k - 1) + Comb(n - 1, k)  
 *            = 1                                    daca k == 0 || k == n 
 */ 
#include <iostream>
using namespace std;

const int N = 200, MOD = 871021;
int C[N][N];
int cnt;

int Comb(int n, int k)
{
	for (int i = 0; i <= n; ++i)
	{
		C[i][0] = C[i][i] = 1;
		cnt++;
	}
		
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			cnt++;
		}
	
	return C[n][k];
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << Comb(n, k) << '\n';
	cout << cnt;
}
