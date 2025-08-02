/* Cmmdc a N numere naturale
 * 
 * CmmdcN(n) = Cmmdc2(CmmdcN(n - 1), a[n])
             = 0 daca n = 0     
 */ 
#include <fstream>
using namespace std;

ifstream fin("cmmdcn.in");
ofstream fout("cmmdcn.out");

const int N = 1000;
int a[N], n;

void CitesteSir();
int Cmmdc2(int a, int b);
int CmmdcN(int n); // returneaza cmmdc a primelor n numere din sir

int main()
{
	CitesteSir();
	fout << CmmdcN(n);
}

int CmmdcN(int n)
{
	if (n == 0)  // daca nu mai sunt elem in sir
		return 0;
	return Cmmdc2(CmmdcN(n - 1), a[n]);
}

int Cmmdc2(int a, int b)
{
	if (b == 0) return a;
	return Cmmdc2(b, a % b);
}

void CitesteSir()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
}






