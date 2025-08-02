/* B10    B2
 * 0      0
 * 1      1
 * 2     10 
 * 3     11
 * 4    100 
 * 5    101
 * 6    110
 * 7    111
 * 8   1000 
 * 9   1001
 * 10  1010
 * 11  1011
 * 12  1100
 * 13  1101
 * 14  1110
 * 15  1111
 * 16 10000
 * 17 10001 
 * =====================
 * 
 * 1  0  1  0  1  1
 * b5 b4 b3 b2 b1 b0
 * 
 * 
 * B10
 *   9+
 *   1
 * ===
 *  10
 * 
 *  B8
 *   7+
 *   1
 * ===
 *  10
 * 
 * 
 *  B2
 *    1+
 *    1
 *  ===
 *   10
 * 
 * ============================
 * n = 93485
 * 
 * cifrele - baza 10
 * while (n)
 * {
 * 		cout << n % 10;
 *      n /= 10;
 * }
 * 
 * cifrele - baza 7
 * while (n)
 * {
 * 		cout << n % 7;
 *      n /= 7;
 * }
 * 
 * cifrele - baza 2
 * while (n)
 * {
 * 		cout << n % 2;  // ultima cifra in baza 2
 *      n /= 2;         // tai ultimul bit din reprezentarea binara a lui n  
 * }
 * 
 */ 
#include <iostream>
using namespace std;

// afiseaza cifrele lui n in baza b
void BazaB(int n, int b)
{
	if (n == 0) return;
	BazaB(n / b, b);
	cout << n % b;
}

int main()
{
	int n, b;
	cin >> n >> b;
	BazaB(n, b);
}




