/* Cmmdc a doua numere naturale
 * Metoda scaderilor (repetate)
 * Complexitate:O(max(a, b))
 * 
 * 
 * Cmmdc(a, b) = Cmmdc(a - b, b) daca a > b
 *             = Cmmdc(a, b - a) daca b > a
 *             = a               daca a = b
 * 
 * a   b
 * 16  12
 *  4  12
 *  4   8
 *  4   4
 * =======
 * cmmdc = 4 
 * 
 * * a    b
 * 16000  1
 *  4  12
 *  4   8
 *  4   4
 * =======
 * cmmdc = 4 
 
 */ 
#include <iostream>
using namespace std;


/*
 * a > 0, b >= 0
 * sau
 * a > 0, b > 0
 */ 
                
int Cmmdc2(int a, int b)
{
	if (b == 0) return a;
	if (a == 0) return b;
	if (a == b) return a;
	
	if (a > b)
		return Cmmdc2(a - b, b);

	return Cmmdc2(a, b - a);
}

int main()
{
	int x, y;
	cin >> x >> y;

	cout << Cmmdc2(x, y);
}
