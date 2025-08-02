/* Gradele nodurilor (G.N.)
 * 
 * Gradul unui nod x este:
 * 1. Nr de vecini ai lui x
 * 2. Nr de muchii INCIDENTE nodului x
 * 3. Nr de noduri adiacente cu x
 * 
 */ 
#include <fstream>
using namespace std;

const int N = 101;
int g[N];     // retine gradele nodurilor  
int n;        // numarul de noduri

void CitesteGraf();
void ScrieGrade();

int main()
{
	CitesteGraf();
	ScrieGrade();
}

void CitesteGraf()
{
	ifstream fin("graf1.in");
	fin >> n;
	int x, y;
	while (fin >> x >> y)
	{
		g[x]++;
		g[y]++;
	}
} 

void ScrieGrade()
{
	ofstream fout("graf1.out");
	for (int nod = 1; nod <= n; ++nod)
		fout << g[nod] << ' ';
}

