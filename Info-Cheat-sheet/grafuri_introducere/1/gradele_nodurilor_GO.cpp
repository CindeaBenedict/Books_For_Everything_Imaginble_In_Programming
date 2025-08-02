/* Gradele nodurilor (G.O.)
 * 
 * Gradul interior al unui nod x este:
 * Nr de arce INCIDENTE spre interior  ale nodului x (cate intra)
 
 * Gradul exterior al unui nod x este:
 * Nr de arce INCIDENTE spre exterior ale nodului x (cate ies)
 */ 
#include <fstream>
using namespace std;

const int N = 101;
int ge[N];     // gradele exterioare (externe)
int gi[N];     // gradele interioare (interne)
int n;         // numarul de varfuri

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
		ge[x]++;
		gi[y]++;
	}
} 

void ScrieGrade()
{
	ofstream fout("graf1.out");
	fout << "Gradele exterioare: ";
	for (int nod = 1; nod <= n; ++nod)
		fout << ge[nod] << ' ';
		
	fout << '\n';
	fout << "Gradele interioare: ";
	for (int nod = 1; nod <= n; ++nod)
		fout << gi[nod] << ' ';
	
}

