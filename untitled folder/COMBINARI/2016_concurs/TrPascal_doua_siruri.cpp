/*
 * Formula recurenta a combinarilor:
 * Comb(n, k) = Comb(n - 1, k - 1) + Comb(n - 1, k)  
 *            = 1                                    daca k == 0 || k == n 
 */ 
#include <iostream>
using namespace std;


void TrPascal(int r, int c[])
{
	int b[35];	
	b[0] = 1;
	for (int i = 1; i <= r; ++i)
	{
		c[0] = c[i] = 1;
		for (int j = 1; j < i; ++j)
			c[j] = b[j - 1] + b[j];
			
		for (int j = 0; j <= i; ++j)
			b[j] = c[j];
	}
}

int main()
{
	int r, c[35];
	
	cin >> r;
	TrPascal(r, c);
	
	for (int j = 0; j <= r; ++j)
		cout << c[j] << ' ';
}




