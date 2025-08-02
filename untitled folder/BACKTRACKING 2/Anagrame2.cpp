/* Generarea anagramelor DISTINTE ale unui cuvant
 * in ordine lexicografica
 * Complexitate: O(n!)
 *   
 */
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream fin("anagrame.in");
ofstream fout("anagrame.out");

int x[15];   // generam pozitii din sirul c[]
char c[15];  // cuvantul
int n;       // nr de litere
int nrsol;

void ScrieSol();
void Anagrame(int k);
bool Ok(int k);

int main()
{
	fin >> c;
	n = strlen(c);
	sort(c, c + n);
	Anagrame(1);
	
	fout << nrsol << " solutii!";
}

void Anagrame(int k)
{
	if (k > n)
	{
		ScrieSol();
		return;
	}
	
	for (int i = 0; i < n; ++i)
	{
		x[k] = i;
		if (Ok(k))
			Anagrame(k + 1);
	}
}

void ScrieSol()
{
	nrsol++;
	for (int i = 1; i <= n; ++i)
		fout << c[x[i]];
	fout << '\n';
}

bool Ok(int k)
{
	for (int i = 1; i < k; ++i)
		if (x[i] == x[k]  || (c[x[k]] == c[x[i]] && x[i] > x[k]))
			return false;
	return true;
}



 


