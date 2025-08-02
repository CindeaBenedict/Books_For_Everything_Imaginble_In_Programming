#include <fstream>
using namespace std;

ifstream fin("adiacenta.in");
ofstream fout("adiacenta.out");

const int MaxN = 101;
bool a[MaxN][MaxN];
int n; // nr de noduri
int m; // nr de muchii

void CitesteGraf();
void ScrieMatrAdiacenta();

int main()
{
	CitesteGraf();
	ScrieMatrAdiacenta();
	
}

void ScrieMatrAdiacenta()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			fout << a[i][j] << ' ';
		fout << '\n';
	}
}

void CitesteGraf()
{
	fin >> n >> m;
	int x, y;
	
	for (int  i = 1; i <= m; ++i)
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = true;
	}
}



