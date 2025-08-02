#include <iostream>
using namespace std;

const int DIM = 101;
int a[DIM][DIM], n, m;

// returneaza suma elem pare din submatricea i1, i2, j1, j2
long long Suma(int i1, int i2, int j1, int j2);
void CitesteMatrice();

int main()
{
	CitesteMatrice();
	cout << Suma(1, n, 1, m);
}

long long Suma(int i1, int i2, int j1, int j2)
{
	if (i1 > i2 || j1 > j2) return 0; // nu exista submatrice
	
	if (i1 == i2 && j1 == j2)   // o singura celula
	{
		if (a[i1][j1] % 2 == 0)
			return a[i1][j1];
		return 0;
	}
	
	int ml = (i1 + i2) / 2;
	int mc = (j1 + j2) / 2;

	return Suma(i1, ml, j1, mc) +
		   Suma(i1, ml, mc + 1, j2) +
		   Suma(ml + 1, i2, mc + 1, j2) + 
		   Suma(ml + 1, i2, j1, mc);
}

void CitesteMatrice()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
}
