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

int CountBit(int n)
{
	int cnt = 0;
	
	while (n)
	{
		n = n & (n - 1);
		cnt++;
	}
	return cnt;
}
	

int main()
{
	int n;
	cin >> n;
	B2(n);
	
//	B2(n & (n - 1));  // n & (n - 1) este n in care ultimul bit 1 devine 0
	cout << CountBit(n);
}





