/* Nr bitilor de 1
 */ 
#include <iostream>
#include <cmath>
using namespace std;

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
	
	B2(n & -n);  // este ultima putere a lui 2 din descompunerea lui n in sume de puteri ale lui 2
}





