#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

using VB  = vector<bool>;
using SI  = set<int>;
using VSI = vector<SI>;

int n;
VSI G;
VB v; 

void CitesteGraf();
void Dfs(int x);

int main()
{
	CitesteGraf();
	Dfs(1);
}

void Dfs(int x) // O(m)
{
	v[x] = true;
	fout << x << ' ';
	for (int y : G[x])
		if (!v[y])
			Dfs(y);
}

void CitesteGraf()
{
	fin >> n;
	G = VSI(n + 1); // acum exista G[0], G[1], ..., G[n] - vectori vizi
	v = VB(n + 1);  // acum exista v[0], v[1], ..., v[n] 
	
	int x, y;
	while (fin >> x >> y)
	{
		G[x].insert(y);
		G[y].insert(x);
	}
	
}
