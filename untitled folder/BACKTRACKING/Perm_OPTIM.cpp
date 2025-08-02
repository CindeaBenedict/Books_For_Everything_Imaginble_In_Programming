/* Genrarea permutarilor
 * Complexitate: O(n!)
 * 
 */
#include <iostream>
using namespace std;

int x[15];
bool p[15];  // p[i] = true daca i a fost "pus" in sirul x[]
int n;       // nr de elem ale multimii
int nrsol;

void ScrieSol();
void Perm(int k);

int main()
{
	cin >> n;
	Perm(1);
	
	cout << nrsol << " solutii!";
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
		if (p[i] == false)
		{
			p[i] = true;
			Perm(k + 1);
			p[i] = false;
		}
	}
}

void ScrieSol()
{
	nrsol++;
	for (int i = 1; i <= n; ++i)
		cout << x[i] << ' ';
	cout << '\n';
}



 


