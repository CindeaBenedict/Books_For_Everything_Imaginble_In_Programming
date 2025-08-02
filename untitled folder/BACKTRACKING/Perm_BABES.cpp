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

void ScrieSol(int x[], int n);
void Perm(int x[], int n, int k, bool final);
bool Ok(int x[], int k);

int main()
{
	int x[15] = {0}; 
	//sau x[1] = 0; 
	int k = 1;
	cin >> n;
	Perm(x, n, k, false);
	
	cout << nrsol << " solutii!";
	
}

void Perm(int x[], int n, int k, bool final)
{
	// trebuie sa ne asiguram ca x[1] = 0;
	while (final == false)
	{
		while (x[k] < n)  // daca val curenta mai poate fi marita
		{
			x[k]++;
			if (Ok(x, k))
			{
				if (k == n)
					ScrieSol(x, n);
				{
					k++;
					x[k] = 0;
				}
			}
		}
		
		if (k > 1)
			k--;
		else
			final = true;
	}
}

void ScrieSol(int x[], int n)
{
	nrsol++;
	for (int i = 1; i <= n; ++i)
		cout << x[i] << ' ';
	cout << '\n';
}

bool Ok(int x[], int k)
{
	for (int i = 1; i < k; ++i)
		if (x[i] == x[k])
			return false;
	return true;
}



 


