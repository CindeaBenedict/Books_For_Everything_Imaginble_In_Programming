
#include <iostream>
using namespace std;

// nu afiseaza bine numerele negative
void B2(int n)   // un int ocupa 4 bytes adica 32 biti
{
	for (int b = 31; b >= 0; --b)
		if (n & (1 << b))
			cout << 1;
		else
			cout << 0;
			
	cout << '\n';
}

int main()
{
	int n;
	cin >> n;
	B2(n);
}





