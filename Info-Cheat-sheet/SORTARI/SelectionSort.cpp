/* Selection Sort
 * Sortarea prin Selectie (a minimului)
 * 
 * Complexitate: O(n^2) - nefluctuanta
 * 
 */ 
#include <fstream>
using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

const int N = 1000;
int a[N], n;

void CitesteSir();
void SelectionSort();
void ScrieSir();


int main()
{
	CitesteSir();
	SelectionSort();
	ScrieSir();
}

/*
 *   1    4    5    7    8    9
 * a[1] a[2] a[3] a[4] a[5] a[6] 
 *                       i        j
 *                      pmin
 * 
 * pmin = poz minimului in intervalul [i..n]
 * 
 * NrIteratii: n-1 + n-2+ ..+ 2 + 1 = n * (n - 1) / 2;
 * 
 * O(n * (n - 1) / 2) = O(n^2 / 2 - n / 2) = O(n^2 / 2) = O(n^2)
 */ 

void SelectionSort()
{
	for (int i = 1; i <= n; ++i)
	{
		int pmin = i;
		for (int j = i + 1; j <= n; ++j)
			if (a[j] < a[pmin])
				pmin = j;
				
		if (i != pmin)
			swap(a[i], a[pmin]);
	}
}

void CitesteSir()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
}

void ScrieSir()
{
	for (int i = 1; i <= n; ++i)
		fout << a[i] << ' ';
}
