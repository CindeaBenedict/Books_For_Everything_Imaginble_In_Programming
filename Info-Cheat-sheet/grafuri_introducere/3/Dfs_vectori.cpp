#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

using VB  = vector<bool>;
using VI  = vector<int>;
using VVI = vector<VI>;

int n;
VVI G;
VB v; 

void CitesteGraf();
void Dfs(int x);

int main()
{
	CitesteGraf();
	Dfs(1);
}

void Dfs(int x)
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
	G = VVI(n + 1); // acum exista G[0], G[1], ..., G[n] - vectori vizi
	v = VB(n + 1);  // acum exista v[0], v[1], ..., v[n] 
	
	int x, y;
	while (fin >> x >> y)
	{
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
}
