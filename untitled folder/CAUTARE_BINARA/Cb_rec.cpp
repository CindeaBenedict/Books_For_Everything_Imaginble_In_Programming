/* Cautare Binara (Binary Search)
 * Complexitate: O(log2(n))
 * Obs: se aplica NUMAI pentru secvente ORDONATE!
 * 
 * 
 * Cautare: 
 * 	1. Secventiala: O(n)
 *  2. Binara: O(log2 n)
 * 
 *                 v = -5
 * 5
 *   2    4    4    10   20   60  80   100
 * a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8]
 *                            st                
 *                      dr 
 *                      m   
 */ 

#include <iostream>
using namespace std;

int a[] = {0, 2, 4, 4, 10, 20, 60, 80, 100};
int n = 8;

// returneaza pozitia lui v in a[] sau -1 daca nu exista
int Cb(int st, int dr, int v)   // O(log2(n))
{
	if (st > dr) return -1;
	
	int m = (st + dr) / 2;
	if (v == a[m])	return m;
		
	if (v > a[m])
		return Cb(m + 1, dr, v);
	
	return Cb(st, m - 1, v);
}

int main()
{
	int v;
	cin >> v;
	int p = Cb(1, n, v);
	if (p != -1)
		cout << "S-a gasit " << v << " pe pozitia " << p;
	else
		cout << "Nu s-a gasit " << v;
}



