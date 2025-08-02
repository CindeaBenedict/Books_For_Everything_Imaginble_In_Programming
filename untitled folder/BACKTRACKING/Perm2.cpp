/* Genrarea permutarilor
 * Complexitate: O(n!)
 *   
 *   1    2    3    4   S
 *   1    2    4    3   S   
 *   1    3    2    4   S   
 *   ....
 *   4    3    2    1
 * x[1] x[2] x[3] x[4]
 * P(1) P(2) P(3) P(4) P(5)
 * 
 * 
 * NrSolutii:
 * A = {1, 2, 3, ..., n}
 * 
 *   2    5    1    1
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
void Perm(int k);
bool Ok(int k);

int main()
{
	cin >> n;
	Perm(1);
	
	cout << nrsol << " solutii!";
}

void Perm(int k)
{
	for (int i = 1; i <= n; ++i)
	{
		x[k] = i;
		if (Ok(k))
		{
			if (k == n)
				ScrieSol();
			else
				Perm(k + 1);
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

bool Ok(int k)
{
	for (int i = 1; i < k; ++i)
		if (x[i] == x[k])
			return false;
	return true;
}



 


