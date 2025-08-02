#include <iostream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

using VI  = vector<int>;
using VVI = vector<VI>;
int n;

VVI G; 

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
			cout << y << ' ';
		cout << '\n';
	}
}

void CitesteGraf()
{
	fin >> n;
	G = VVI(n + 1); // acum exista G[0], G[1], ..., G[n] - vectori vizi
	int x, y;
	while (fin >> x >> y)
	{
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
}
