/* Cautare Binara (Binary Search)
 * Complexitate: O(log2(n))
 * Obs: se aplica NUMAI pentru secvente ORDONATE!
 * 
 * 
 * Cautare: 
 * 	1. Secventiala: O(n)
 *  2. Binara: O(log2 n)
 * 
 *                 v = 70
 * 
 *   2    4    4    10   20   60  80   100
 * a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8]
 * 
 * 
 */ 

#include <iostream>
using namespace std;

int a[] = {0, 2, 4, 4, 10, 20, 60, 80, 100};
int n = 8;

// returneaza poz lui v in a[] sau -1 daca nu exista
int Cb(int v)   // O(log2(n))
{
	// OPTIONAL
	if (v > a[n]) return -1;
	if (v < a[1]) return -1;
	
	int st = 1, dr = n, m;
	
	while (st < dr)   // cat timp mai am un intervalde cautare
	{
		m = (st + dr) / 2;
		if (v == a[m]) 
			return m;
			
		if (v > a[m])
			st = m + 1;
		else
			dr = m - 1;
	}
	
	return -1;
}

int main()
{
	int v;
	cin >> v;
	
	int p = Cb(v);
	if (p != -1)
		cout << p;
	else
		cout << "nu exista";
}



