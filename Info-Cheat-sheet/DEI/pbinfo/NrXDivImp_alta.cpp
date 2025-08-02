#include <iostream>
using namespace std;

int NrXDivImp(int a[], int st, int dr, int x)
{
	if (st == dr) return a[st] == x;
	
	int m = (st + dr) / 2;
	return NrXDivImp(a, st, m, x) + NrXDivImp(a, m + 1, dr, x);	
}


int main()
{
	int a[] = {0, 2, 5, 1, 5, 3, 5, 5, 5, 7, 6};
	

	cout << NrXDivImp(a, 1, 6, 5);
}

