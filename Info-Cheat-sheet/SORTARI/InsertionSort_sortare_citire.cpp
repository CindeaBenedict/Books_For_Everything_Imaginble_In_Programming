/* Insertion Sort
 * Sortarea prin Insertie
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

void InsertionSort();
void ScrieSir();

int main()
{

	InsertionSort();
	ScrieSir();
}

/*
 *                             4 
 *                             x
 *         1    2    3    3    4    5    6
 * a[0]  a[1] a[2] a[3] a[4] a[5] a[6] a[7] 
                               i              
                          j   j+1
 * 
 * NrIteratii: 
 * 
 * O(n * (n - 1) / 2) = O(n^2 / 2 - n / 2) = O(n^2 / 2) = O(n^2)
 */ 

void InsertionSort()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int j, x;
		fin >> x;
		
		for (j = i - 1; j >= 1 && a[j] > x; --j)
			a[j + 1] = a[j];
			
		a[j + 1] = x;
	}
}

void ScrieSir()
{
	for (int i = 1; i <= n; ++i)
		fout << a[i] << ' ';
}
