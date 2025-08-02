#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("estearbore.in");
ofstream fout("estearbore.out");
// type alias-uri

using VI  = vector<int>;
using VB  = vector<bool>;
using SI  = set<int>;
using VSI = vector<SI>;

VI niv;
VSI G;
VB v;
int n;
bool ciclu;

void CitesteArbore();
void Dfs(int x, int nv);

int main()
{
	CitesteArbore();
	
	Dfs(1, 1);
	bool conex = true;
	for (int i = 1; i <= n; ++i)	
		if (!v[i])
		{
			conex = false;
			break;
		}
	if (ciclu || !conex)
		fout << "NU";
	else
		fout << "DA";
	
}

void Dfs(int x, int nv)
{
	if (ciclu)	return;
	v[x] = true;
	niv[x] = nv;
	
	for (int y : G[x])
		if (!v[y])
			Dfs(y, nv + 1);
		else
			if (niv[x] - niv[y] > 1)
			{
				ciclu = true;
				break;
			}
}

void CitesteArbore()
{
	fin >> n;
	G = VSI(n + 1);
	v = VB(n + 1);
	niv = VI(n + 1);
	int x, y;
	
	while (fin >> x >> y)
	{
		G[x].insert(y);
		G[y].insert(x);
	}
}


