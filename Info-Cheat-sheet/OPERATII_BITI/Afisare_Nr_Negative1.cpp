
#include <iostream>
using namespace std;

// nu afiseaza bine numerele negative
void B2(int n)
{
	if (n == 0)	return;

	B2(n / 2);
	cout << n % 2;
}

int main()
{
	int n;
	cin >> n;
	
	B2(-n);
}





