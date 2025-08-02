/* Bubble Sort
 * Sortarea prin metoda Bulelor
 * 
 * Complexitate: O(n^2) - fluctuanta
 * Pe caul cel mai favorabil (sirul era initial sortat)
 * complexitatea devine O(n)
 * 
 */ 
#include <fstream>
using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

const int N = 1000;
int a[N], n;

void CitesteSir();
void BubbleSort();
void ScrieSir();

int main()
{
	CitesteSir();
	BubbleSort();
	ScrieSir();
}

/*
 * sortat = true;
 * 
 *   2    3    4    6    7    9
 * a[1] a[2] a[3] a[4] a[5] a[6] 
               i   i+1
 * 
 * NrIteratii: n-1 + n-2 + n-3 + ... + 2 + 1 = n * (n - 1) / 2;
 * 
 * O(n * (n - 1) / 2) = O(n^2 / 2 - n / 2) = O(n^2 / 2) = O(n^2)
 */ 

void BubbleSort()
{
	bool sortat = false;
	for (int k = 1; !sortat; ++k)
	{
		sortat = true;
		for (int i = 1; i <= n - k; ++i)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				sortat = false;
			}
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
