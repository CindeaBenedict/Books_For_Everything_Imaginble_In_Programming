// Matrice de adiacenta - G.N.
#include <fstream>
using namespace std;

const int N = 101;
bool a[N][N]; // matricea de adiacenta
int n;       // numarul de noduri
int m;       // nr de muchii

void CitesteGraf();
void ScrieMatrAdiacenta();

int main()
{
	CitesteGraf();
	ScrieMatrAdiacenta();
}

void CitesteGraf()
{
	ifstream fin("graf.in");
	fin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; ++i)
	{
		fin >> x >> y;
		a[x][y] = true;
		a[y][x] = true;	
	}
} 

void ScrieMatrAdiacenta()
{
	ofstream fout("graf.out");
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			fout << a[i][j] << ' ';
		fout << '\n';
	}
}

