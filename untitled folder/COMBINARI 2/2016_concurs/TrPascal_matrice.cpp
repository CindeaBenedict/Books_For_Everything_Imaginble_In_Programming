/*
 * Formula recurenta a combinarilor:
 * Comb(n, k) = Comb(n - 1, k - 1) + Comb(n - 1, k)  
 *            = 1                                    daca k == 0 || k == n 
 */ 
#include <iostream>
using namespace std;


void TrPascal(int r, int c[])
{
	int C[35][35];	
	
	for (int i = 0; i <= r; ++i)
		C[i][0] = C[i][i] = 1;
		
	for (int i = 2; i <= r; ++i)
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	
	for (int j = 0; j <= r; ++j)
		c[j] = C[r][j];
}

int main()
{
	int r, c[35];
	
	cin >> r;
	TrPascal(r, c);
	
	for (int j = 0; j <= r; ++j)
		cout << c[j] << ' ';
}




