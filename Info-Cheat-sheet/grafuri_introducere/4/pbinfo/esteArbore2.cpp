#include <fstream>
#include <vector>
#include <set>
#include <cmath>
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

void CitesteArbore();
bool AreCiclu(int x, int nv);

int main()
{
	CitesteArbore();
	
	bool ciclu = AreCiclu(1, 1);
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

bool AreCiclu(int x, int nv)
{
	v[x] = true;
	niv[x] = nv;
	
	for (int y : G[x])
		if (!v[y])
		{
			bool ciclu = AreCiclu(y, nv + 1);
			if (ciclu)
				return true;
		}
		else
			if (abs(niv[x] - niv[y]) > 1)
				return true;
			
	return false;
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


