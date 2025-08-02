/* Quick Sort
 * Sortarea rapida
 * Metoda: Divide et Impera 
 * Complexitate: O(n * log2(n)) - fluctuanta
 * 
 */ 
#include <fstream>
using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

const int N = 10000;
int a[N], n;

void CitesteSir();
void QuickSort(int st, int dr);
void ScrieSir();

int main()
{
	CitesteSir();
	QuickSort(1, n);
	ScrieSir();
}

/*
 *                       7
 *                       p
 *   3    2    7    4    7    20   11    7    10   8   
 * a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9] a[10]
    st                                            dr  
                              i
                    j
 */ 

void QuickSort(int st, int dr)  // sorteaza intervalul [a[st]... a[dr]]
{	
	int pivot = a[(st + dr) / 2];
	int i = st, j = dr;
	
	while (i <= j)
	{
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	
	if (st < j) QuickSort(st, j);
	if (i < dr) QuickSort(i, dr);
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
