#include <fstream>
#include <iostream>
using namespace std;

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

bool Palindrom(int n)
{
	return n == Oglindit(n);
}

int main()
{
	int n;
	cin >> n;
	if (Palindrom(n))
		cout << n << " este palindrom";
	else
		cout << n << " nu este palindrom";
		
}
