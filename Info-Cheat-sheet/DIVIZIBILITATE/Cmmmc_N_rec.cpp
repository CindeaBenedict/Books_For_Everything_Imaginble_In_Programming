/* Cmmmc a N numere naturale
 * 
 * cmmmc(a, b, c) = cmmmc(cmmmc(a, b), c)
 */ 
#include <fstream>
using namespace std;

ifstream fin("cmmdcn.in");
ofstream fout("cmmdcn.out");

const int N = 1000;
int a[N], n;

void CitesteSir();
int Cmmdc2(int a, int b);
int Cmmmc2(int a, int b); // cmmmc a 2 numere
int CmmmcN(int n);             // returneaza cmmmc a primelor n numere din sir

int main()
{
	CitesteSir();
	fout << CmmmcN(n);
}

int CmmmcN(int n)
{
	if (n == 0)
		return 1;  // ATENTIE!! nu merge cu 0
	return Cmmmc2(CmmmcN(n - 1), a[n]);
}

int Cmmmc2(int a, int b)
{
	return a * b / Cmmdc2(a, b);
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






