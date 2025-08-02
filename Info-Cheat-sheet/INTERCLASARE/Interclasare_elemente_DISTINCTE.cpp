/* Interclasarea a doua siruri
 *
 * Se dau doua siruri a[] si b[], ordinate crescator.
 * Sa se afiseze in ordine crescatoare toate elementele DISTINCTE, comune si necomune
 * celor doua siruri, 
 * 
 *   2    4    6    8    10
 * a[1] a[2] a[3] a[4] a[5]   n = 5
 *                            i
 * 
 *   1    4    4    7   10    11  11   15
 * b[1] b[2] b[3] b[4] b[5] b[6] b[7] b[8]   m = 8
 *                                        j
 *  
 *                              ant = 15
 * 
     1    2    4     6   7    8   10    11   15
 * c[1] c[2] c[3] c[4] c[5] c[6] c[7] c[8] c[9]   
                                         k                                                             
 * 
 */ 
#include <fstream>
using namespace std;

ifstream fin("interclas.in");
ofstream fout("interclas.out");

const int N = 1000;

void CitesteSiruri(int a[], int& n, int b[], int& m);
void ScrieSir(int a[], int n);
void Interclaseaza(int a[], int n, int b[], int m, int c[], int& k);

int main()
{
	/*
	 * Complexitate:
	 * 1. O(3*(n + m)) = O(n + m) - timp de executare
	 * 
	 * 2. O(4 * n)  = O(n)   - spatiu de memorie ocupat
	 * 
	 */ 
	int a[N], n;
	int b[N], m;
	int c[2 * N], k;
	
	CitesteSiruri(a, n, b, m);        // O(n + m) 
	Interclaseaza(a, n, b, m, c, k);  // O(n + m)
	ScrieSir(c, k);                   // O(n + m)
}

// O(n + m) - liniara
void Interclaseaza(int a[], int n, int b[], int m, int c[], int& k)
{
	int i = 1, j = 1;
	k = 0;
	int ant = -1;
	while (i <= n && j <= m)
		if (a[i] < b[j])
		{
			if (a[i] != ant)
			{
				c[++k] = a[i];
				ant = a[i];
			}
			i++;
		}
		else
			if (b[j] < a[i])
			{
				if (b[j] != ant)
				{
					c[++k] = b[j];
					ant = b[j];
				}
				j++;
			}
			else
			{
				if (a[i] != ant)
				{
					c[++k] = a[i];
					ant = a[i];
				}
				i++;
				j++;
			}
	
	while (j <= m)
	{
		if (b[j] != ant)
		{
			c[++k] = b[j];
			ant = b[j];
		}
		j++;
	}
		
	while (i <= n)
	{
		if (a[i] != ant)
		{
			c[++k] = a[i];
			ant = a[i];
		}
		i++;
	}
}

void CitesteSiruri(int a[], int& n, int b[], int& m)
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
		
	fin >> m;
	for (int i = 1; i <= m; ++i)
		fin >> b[i];
}

void ScrieSir(int a[], int n)
{
	for (int i = 1; i <= n; ++i)
		fout << a[i] << ' ';
	fout << '\n';
}




