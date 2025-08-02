/* Generarea permutarilor
 * Complexitate: O(n!)
 *   
 *   1    2    4    4
 *   4    3    2    1
 * x[1] x[2] x[3] x[4]
     k


 * x[1] x[2] x[3] x[4]....       x[n]
 *            k-1   k
 *   n *(n-1)*(n-2)* .... 2 * 1  = n!
 * 
 */
#include <iostream>
using namespace std;

int x[15];
int n;     // nr de elem ale multimii
int nrsol;

void ScrieSol();
void Perm();
bool Ok(int k);

int main()
{
	
	
	
	cin >> n;
	Perm();
	
	cout << nrsol << " solutii!";
	
}

void Perm()
{
	int k = 1;
	// trebuie sa ne asiguram ca x[1] = 0;
	while (k >= 1)
	{
		while (x[k] < n)  // daca val curenta mai poate fi marita
		{
			x[k]++;
			if (Ok(k))
			{
				if (k == n)
					ScrieSol();
				{
					k++;
					x[k] = 0;
				}
			}
		}
		
		k--;
	}
}

void ScrieSol()
{
	nrsol++;
	for (int i = 1; i <= n; ++i)
		cout << x[i] << ' ';
	cout << '\n';
}

bool Ok(int k)
{
	for (int i = 1; i < k; ++i)
		if (x[i] == x[k])
			return false;
	return true;
}



 


