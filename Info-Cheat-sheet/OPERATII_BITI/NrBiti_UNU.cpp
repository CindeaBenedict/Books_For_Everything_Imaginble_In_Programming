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

int CountBit1(int n)
{
	int cnt = 0;
	while (n)
	{
		if (n % 2 == 1)  // daca ultimul bit este 1
			cnt++;       // numaram ultimul bit
		n /= 2; // "taiem" ultimul bit
	}
	
	return cnt;
}

int CountBit2(int n)
{
	int cnt = 0;
	while (n)
	{
		if (n & 1)    // daca ultimul bit este 1
			cnt++;    // numaram ultimul bit
		n >>= 1;  // n = n >> 1;
	}
	
	return cnt;
}

int CountBit3(int n)   // un int ocupa 4 bytes adica 32 biti
{
	int cnt = 0;
	for (int b = 31; b >= 0; --b)
		if (n & (1 << b))
			cnt++;
			
	return cnt;
}

int CountBit4(int n)  // s-a dat
{
	int cnt = 0;
	
	while (n)
	{
		n = n & (n - 1);
		cnt++;
	}
	return cnt;
}

int CountBit5(int n) // inca nu s-a dat
{
	int cnt = 0;
	
	while (n)
	{
		n -= n & -n;    // n = n - (n & -n);
		cnt++;
	}
	return cnt;
}

int CountBit6(int n) // nu se va da  (functie a compilatorului gcc)
{
	return __builtin_popcount(n);
}

int main()
{
	int n;
	cin >> n;
	B2(n);
	cout << CountBit1(n) << '\n';
	cout << CountBit2(n) << '\n';
	cout << CountBit3(n) << '\n';
	cout << CountBit4(n) << '\n';
	cout << CountBit5(n) << '\n';
	cout << CountBit6(n) << '\n';
}





