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
 *                            p1  p2              
 *     
 * p1 = poz celei mai mari valori a.i. a[p1] <= v                
 * p2 = poz celei mai mici valori a.i. a[p2] >= v                
 */ 

#include <iostream>
using namespace std;

int a[] = {0, 2, 4, 4, 10, 20, 60, 80, 100};
int n = 8;

// returneaza celei mai din dreapta poz p1, a.i. a[p1] <= v
int Cb1(int v)   // O(log2(n))
{
	int st = 1, dr = n, m;
	int poz = -1;   // in caz ca nu exista 
	while (st < dr)   // cat timp mai am un intervalde cautare
	{
		m = (st + dr) / 2;
		if (a[m] <= v)
		{
			poz = m;
			st = m + 1;
		}
		else
			dr = m - 1;
	}
	
	return poz;
}

// returneaza celei mai din stanga poz p2, a.i. a[p2] >= v
int Cb2(int v)   // O(log2(n))
{
	int st = 1, dr = n, m;
	int poz = -1;   // in caz ca nu exista 
	while (st <= dr)   // cat timp mai am un interval de cautare
	{
		m = (st + dr) / 2;
		if (a[m] >= v)
		{
			poz = m;
			dr = m - 1;
		}
		else
			st = m + 1;
	}
	
	return poz;
}

int main()
{
	int v;
	cin >> v;
	
	cout << Cb1(v) << ' ' << Cb2(v);
}



