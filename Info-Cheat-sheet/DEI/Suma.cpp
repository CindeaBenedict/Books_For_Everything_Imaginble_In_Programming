/*  Divide et Impera
	Complexitate: O(n)
	Nr oper: n - 1
	Este o tehnica algoritmica recursiva
	
	Metoda:
	1. Se divizeaza problema in doua sau mai multe subprobleme
	2. Se rezolva subproblemle
	3. Se combina rezultatele subproblemelor pt a obtine rezultatul problemei
 * 
 */ 
#include <iostream>
using namespace std;

// * Suma elem unui sir
int a[] = {0, 2, 1, 7, 4, 9, 10};
int n = 6;

// returneaza suma a[st...dr]
int Suma(int st, int dr)
{
	if (st == dr) return a[st];
	
	int m = (st + dr) / 2;
	
	// divide
	int s1 = Suma(st, m);      // suma a[st] + ... + a[m]
	int s2 = Suma(m + 1, dr);  // suma a[m + 1] + ... + a[dr]
	
	// impera
	return s1 + s2;
}

int main()
{
	cout << Suma(1, n);
}

