
#include <iostream>
using namespace std;

// nu afiseaza bine numerele negative
void B2(int n)   // un int ocupa 4 bytes adica 32 biti
{
	bool first = false;  // trece pe true la primul bit 1 intalnit
	for (int b = 31; b >= 0; --b)
		if (n & (1 << b))
		{
			if (!first)
				first = true;
			cout << 1;
		}
		else
			if (first)
				cout << 0;
			
	cout << '\n';
}

int main()
{
	int n;
	cin >> n;
	B2(n);
}





