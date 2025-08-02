#include <iostream>
using namespace std;

int a[101];
int n;

void CitesteSir();
bool ExistaImpare(int st, int dr);

int main()
{
	CitesteSir();
	if (ExistaImpare(1, n))
		cout << "DA";
	else
		cout << "NU";
	return 0;
}

bool ExistaImpare(int st, int dr)
{
	if (st == dr)
	{
		if (a[st] % 2 == 1)
			return true;
		return false;
	}
	
	int m = (st + dr) / 2;
	return ExistaImpare(st, m) || ExistaImpare(m + 1, dr);
}

void CitesteSir()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
}
