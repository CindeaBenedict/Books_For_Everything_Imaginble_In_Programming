/* Interclasarea a doua siruri
 * ATENTIE! sirurile trebuie sa fie ORDONATE
 * 
 * Se dau doua siruri a[] si b[], ordinate crescator.
 * Sa se creeze un al treilea sir c[], ordonat crescator
 * care sa contina toate elemente din a[] si din b[]
 * 
 *   2    4    6    8    9
 * a[1] a[2] a[3] a[4] a[5]   n = 5
 *                          i
 * 
 *   1    4    5    7   10    11  15
 * b[1] b[2] b[3] b[4] b[5] b[6] b[7]   m = 7
 *                       j
 *  
 *   1    2    4    4    5    6    7    8    9    10    11    15
 * c[1] c[2] c[3] c[4] c[5] c[6] c[7] c[8] c[9] c[10] c[11] c[12]   k = 12
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
	while (i <= n && j <= m)
		if (a[i] <= b[j])
			c[++k] = a[i++];
		else
			c[++k] = b[j++];
	
	while (j <= m)
		c[++k] = b[j++];
		
	while (i <= n)
		c[++k] = a[i++];
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




