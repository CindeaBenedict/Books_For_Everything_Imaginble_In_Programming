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
int cnt;

int Comb(int n, int k)
{
	cnt++;
	if (k == 0 || n == k)
		return 1;
	
	return (Comb(n - 1, k - 1) + Comb(n - 1, k)) % MOD;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << Comb(n, k) << '\n';
	cout << cnt;
	
}
