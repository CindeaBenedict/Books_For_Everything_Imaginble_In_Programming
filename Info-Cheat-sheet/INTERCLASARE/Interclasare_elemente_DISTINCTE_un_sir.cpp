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

int main()
{
	/*
	 * Complexitate:
	 * 1. O(2*n + m) = O(n + m) - timp de executare
	 * 
	 * 2. O(n)   - spatiu de memorie ocupat
	 * 
	 */ 
	int a[N], n;
	int bj, m;
	fin >> n;
	for (int i = 1; i <= n; ++i)   // O(n)
		fin >> a[i];
		
	fin >> m;
	fin >> bj;   // citim b[1]
	int i = 1, j = 1;
	int ant = -1;
	while (i <= n && j <= m)      // O(n + m) 
		if (a[i] < bj)
		{
			if (a[i] != ant)
			{
				fout << a[i] << ' ';
				ant = a[i];
			}
			i++;
		}
		else
			if (bj < a[i])
			{
				if (bj != ant)
				{
					fout << bj << ' ';
					ant = bj;
				}
				j++; fin >> bj;
			}
			else
			{
				if (a[i] != ant)
				{
					fout << a[i] << ' ';
					ant = a[i];
				}
				i++;
				j++; fin >> bj;
			}
	
	while (j <= m)
	{
		if (bj != ant)
		{
			fout << bj << ' ';
			ant = bj;
		}
		j++; fin >> bj;
	}
		
	while (i <= n)
	{
		if (a[i] != ant)
		{
			fout << a[i] << ' ';
			ant = a[i];
		}
		i++;
	}	
}

