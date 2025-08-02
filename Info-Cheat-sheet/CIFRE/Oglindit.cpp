#include <fstream>
#include <iostream>
using namespace std;
/*
 * n = 2478
 * 
 * n = 24
 * 
 * ogl = 0
 
 * ogl = 8
 * ogl = 87  = 8 * 10 + 7
 * ogl = 874 = 87 * 10 + 4
 * 
 * ogl = ogl * 10 + n % 10;
 */ 
int Oglindit(int n)
{
	int ogl = 0;
	while (n)
	{
		ogl = ogl * 10 + n % 10;
		n /= 10;
	}
	return ogl;
}

int main()
{
	int n;
	cin >> n;
	cout << Oglindit(n);
}
