/*
 * Nr de cifre ale lui n in baza b:
 * 
 * c = int(logb(n)) + 1
 * 
 * 
 * n = 2837
 * Cate cifre are in baza 2?
 * 
 * while (n)
 * 	 n /= 2;
 * 
 * Numar    Iteratii
 *   n           0
 *  n / 2       1
 *  n / 2^2     2
 *  n / 2^3     3
 * ....
 * n / 2^k      k
 * 
 * n / 2^k = 1 => 2^k = n => k = log2(n)
 * 
 * Cate cifre are in baza 10?
 * 
 * while (n)
 * 	 n /= 10;
 * 
 * Numar    Iteratii
 *   n           0
 *  n / 10       1
 *  n / 10^2     2
 *  n / 10^3     3
 * ....
 * n / 10^k      k
 * 
 * n / 10^k = 1 => 10^k = n => k = log10(n)
 * 
 * Cate cifre are in baza 7?
 * 
 * while (n)
 * 	 n /= 7;
 * 
 * Numar    Iteratii
 *   n           0
 *  n / 7       1
 *  n / 7^2     2
 *  n / 7^3     3
 * ....
 * n / 7^k      k
 * 
 * n / 7^k = 1 => 7^k = n => k = log7(n)
 */ 
#include <iostream>
#include <cmath>
using namespace std;

void B2(int n)   // un int ocupa 4 bytes adica 32 biti
{
	for (int b = 16; b >= 0; --b)
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
		cnt++;  // numaram ultimul bit
		n /= 2; // "taiem" ultimul bit
	}
	
	return cnt;
}

int CountBit2(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt++;    // numaram ultimul bit
		n >>= 1;  // n = n >> 1;
	}
	
	return cnt;
}

int CountBit3(int n)   // un int ocupa 4 bytes adica 32 biti
{
	int cnt = 0;
	bool first_one = false;
	for (int b = 31; b >= 0; --b)
		if (n & (1 << b))
		{
			if (!first_one)
				first_one = true;
			cnt++;
		}
		else
		{
			if (first_one)
				cnt++;
		}
			
	return cnt;
}

int CountBit4(int n)
{
	return (int)log2(n) + 1;
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
}





