/* Generarea permutarilor elementelor unui sir
 * in ordine invers lexicografica
 * Complexitate: O(n!)
 *   
 */
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("perm_sir.in");
ofstream fout("perm_sir.out");

int x[15];  // generam pozitii din sirul a[]
int a[15];
int n;     // nr de elem ale sirului
int nrsol;

void ScrieSol();
void Perm(int k);
bool Ok(int k);

int main()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
	
	sort(a + 1, a + n + 1, greater<int>());
	Perm(1);
	
	fout << nrsol << " solutii!";
}

void Perm(int k)
{
	if (k > n)
	{
		ScrieSol();
		return;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		x[k] = i;
		if (Ok(k))
			Perm(k + 1);
	}
}

void ScrieSol()
{
	nrsol++;
	for (int i = 1; i <= n; ++i)
		fout << a[x[i]] << ' ';
	fout << '\n';
}

bool Ok(int k)
{
	for (int i = 1; i < k; ++i)
		if (x[i] == x[k])
			return false;
	return true;
}



 


