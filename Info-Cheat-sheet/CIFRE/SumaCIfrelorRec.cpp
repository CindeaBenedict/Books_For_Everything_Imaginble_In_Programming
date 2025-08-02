#include <fstream>
#include <iostream>
using namespace std;

int SumaCif(int n)
{
	if (n == 0) return 0;
	return SumaCif(n / 10) + n % 10;
}

int main()
{
	int n;
	cin >> n;
	cout << SumaCif(n);
}
