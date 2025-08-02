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

VSI G;
VB v;
VI tata; //vectorul de tati
int n;

void CitesteArbore();
bool AreCiclu(int x);

int main()
{
	CitesteArbore();
	
	bool ciclu = AreCiclu(1);
	bool conex = true;
	for (int i = 1; i <= n; ++i)	
		if (!v[i])
		{
			conex = false;
			break;
		}
	if (!conex || ciclu)
		fout << "NU";
	else
		fout << "DA";
}

bool AreCiclu(int x)
{
	v[x] = true;	
	for (int y : G[x])
		if (!v[y]) // daca y este fiul lui x
		{
			tata[y] = x;
			bool ciclu = AreCiclu(y);
			if (ciclu)
				return true;
		}
		else
			if (y != tata[x])
				return true;
	return false;
}

void CitesteArbore()
{
	fin >> n;
	G = VSI(n + 1);
	v = VB(n + 1);
	tata = VI(n + 1);
	int x, y;
	
	while (fin >> x >> y)
	{
		G[x].insert(y);
		G[y].insert(x);
	}
}


