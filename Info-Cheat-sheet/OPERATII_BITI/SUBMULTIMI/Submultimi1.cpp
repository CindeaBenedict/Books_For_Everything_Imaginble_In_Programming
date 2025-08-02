/* Genearea submultimilor unei multimi
 * 
 *              A = {5, 4, 3, 2, 1}
 * 
 * msk               0  0  0  0  0   => { }
 *                   ....
 *                   1  0  1  0  1   => {1, 3, 5} 
 *                   1  1  0  0  0   => {4, 5} 
 *                   ....
 *   2^n - 1         1  1  1  1  1   => {1, 2, 3, 4, 5} 
 * 
 * NrSubm(A)  =      2* 2 *2* 2 *  2 = 2^n          
 * 
 */ 
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for (int msk = 0; msk < 1 << n; ++msk)
	{
		cout << "{ ";
		for (int b = 0; b < n; ++b)
			if (msk & (1 << b))
				cout << b + 1 << ' ';
			
		cout << "}\n";	
	}
}





