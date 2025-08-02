/* Merge Sort
 * Sortarea prin Interclasare
 * Metoda: Divide et IMpera + Interclasare
 * Complexitate: O(n * log2(n)) - nefluctuanta
 * 
 */ 
#include <fstream>
using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

const int N = 1000;
int a[N], n;
int tmp[N];  // sir auxiliar, necesar pt interclasare

void CitesteSir();
void MergeSort(int st, int dr);
void Interclaseaza(int st, int m, int dr);
void ScrieSir();

int main()
{
	CitesteSir();
	MergeSort(1, n);
	ScrieSir();
}

/*
 * 
 *   5    8    1    6    4    2  
 * 
 *   1    5    8    2    4    6  
 * a[1] a[2] a[3] a[4] a[5] a[6] 
    st         m   m+1        dr
 *  i               j 
 * 
 *   1    2    4    5    6    8
 * t[1] t[2] t[3] t[4] t[5] t[6] 
 *        k
 */ 

void MergeSort(int st, int dr)  // sorteaza intervalul [a[st]... a[dr]]
{
	if (st == dr) return;
	int m = (st + dr) / 2;
	MergeSort(st, m);           // sorteaza [a[st] ... a[m]]
	MergeSort(m + 1, dr);       // sorteaza [a[m + 1] ... a[dr]]
	Interclaseaza(st, m, dr);
}

void Interclaseaza(int st, int m, int dr) // O(2 * ( (dr - st))
{
	int i = st, j = m + 1, k = 0;
	while (i <= m && j <= dr)
		if (a[i] <= a[j])
			tmp[++k] = a[i++];
		else
			tmp[++k] = a[j++];
			
	while (i <= m)
		tmp[++k] = a[i++];
		
	while (j <= dr)
		tmp[++k] = a[j++];
	
	// copierea valorilor din sirul auxiliar tmp[] in a[]
	for (int i = st; i <= dr; ++i)
		a[i] = tmp[i - st + 1];
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
