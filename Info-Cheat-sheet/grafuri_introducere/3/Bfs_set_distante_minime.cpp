/* Parcurgere pe Latime (largime)
 * Breadth First Search
 */ 
#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

using VI  = vector<int>;
using VB  = vector<bool>;
using SI  = set<int>;
using VSI = vector<SI>;

int n;
VSI G;
VI d;   // d[x] = distanta minima de la nodul sursa la nodul x
VB v;

void CitesteGraf();
void Bfs(int x);

int main()
{
	CitesteGraf();
	Bfs(2);
	fout << d[6];
}

void Bfs(int x)
{
	queue<int> Q; // coada vida
	Q.push(x);
	d[x] = 0;
	v[x] = true;
//	fout << x << ' ';
	
	while (!Q.empty())  // cat timp coada nu este vida
	{
		x = Q.front();  // aflam primul nod din coada
		Q.pop();        // apoi il stergem 
		
		for (int y : G[x])
			if (!v[y])
			{
				v[y] = true;
				d[y] = d[x] + 1;
				Q.push(y);
//				fout << y << ' ';
			}
	}
}

void CitesteGraf()
{
	fin >> n;
	G = VSI(n + 1);
	v = VB(n + 1);
	d = VI(n + 1);
	int x, y;
	while (fin >> x >> y)
	{
		G[x].insert(y);
		G[y].insert(x);
	}
}


