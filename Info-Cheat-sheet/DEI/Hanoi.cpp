/* Turnurile din Hanoi
 * Complexitate: O(2^n)
 * Nr oper = 1 + 2 + 2^2 + ... + 2^(n - 1) = 2^n - 1
 * 
 * Problema: 
 *    Muta n discuri de pe tija A pe tija C folosind si tija B
 * 		restrictii: 
 * 			1. la o mutare se muta un singur disc
 *          2. un disc se muta doar de pe o tija pe alta
 *          3. nu se poate plasa un disc cu diametru mai mare peste un disc
 *             cu diametrul mai mic
 * 
 * Rezolvare: Divide et Impera
 * 
 * 1. Mut n - 1 discuri de pe A -> B utilizand si C
 * 2. Mut un singur disc A->C
 * 2. Mut n - 1 discuri de pe B->C utlizand si B
 * 
 */ 
#include <iostream>
using namespace std;

int oper;
// muta n - 1 discuri A->C utilizand si C
void Hanoi(int n, char A, char C, char B)
{
	if (n == 0) return;
	Hanoi(n - 1, A, B, C);  // mut n - 1 discuri A->B utilizand C
	oper++;
	cout << A << " ==> " << C << '\n';
	Hanoi(n - 1, B, C, A);  // mut n - 1 discuri B->C utilizand si A
}

int main()
{
	int n;
	cin >> n;
	Hanoi(n, 'A', 'C', 'B');
	cout << oper << ' ' << (1 << n) - 1;
}
