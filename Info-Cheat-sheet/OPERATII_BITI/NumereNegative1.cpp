/* Reprezentarea binara a numereleor intregi negative in memorie
 * 
 * Fie un numar pozitiv n.
 * Pt a obtine reprezentarea binara a lui -n, compilatorul face 
 * urmatoarele operatii:
 * 
 * 1. Se inverseaza toti bitii lui n (cu operatorul ~)
 * 2. Se adauga 1 la rezultat
 * 
 * Deci:
 *    -n = ~n + 1
 */ 
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
	cout << "n      = "; B2(n);
	cout << "~n     = "; B2(~n);
	cout << "~n + 1 = "; B2(~n + 1);
	cout << "-n     = "; B2(-n);
	
}





