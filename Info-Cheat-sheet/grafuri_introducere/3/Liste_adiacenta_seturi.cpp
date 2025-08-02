#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

using SI  = set<int>;
using VSI = vector<SI>;
int n;

VSI G; 

void CitesteGraf();
void ScrieVecini();

int main()
{
	CitesteGraf();
	ScrieVecini();
}

void ScrieVecini()
{
	for (int x = 1; x <= n; ++x)
	{
		for (int y : G[x])
			fout << y << ' ';
		fout << '\n';
	}
}

void CitesteGraf()
{
	fin >> n;
	G = VSI(n + 1); // acum exista G[0], G[1], ..., G[n] - vectori vizi
	int x, y;
	while (fin >> x >> y)
	{
		G[x].insert(y);
		G[y].insert(x);
	}
	
}
