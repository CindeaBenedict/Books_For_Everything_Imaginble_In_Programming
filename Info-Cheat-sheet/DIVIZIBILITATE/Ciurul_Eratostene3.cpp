/* 
 * 	Ciurul lui Eratostene
	Complexitate: O(n)
	Este util cand dorm sa determinam TOATE numerele prime
	din intervalul [1...n]
	
	Algoritmul se aplica cand trebuie testate f multe numere daca sunt prime sau nu
*/
#include <iostream>
using namespace std;

const int N = 100000, VALMAX = 1000001;
int a[N];
int n;
/*
 * Sa se det toate enumerele prime din sirul a[] (a[i] <= 1000000)
 * 
 */ 

bool not_prim[VALMAX + 1];   // not_prim[x] = true daca x NU este prim

void Ciur(int n) // O(n) - unde n este va maxima a valorilor din sirul a[]
{
	not_prim[1] = true;
	
	// demarcam toate numerele care nu sunt prime (cernem) sita
	for (int i = 2; i * i <= n; ++i)  // O(n)
		if (!not_prim[i])  // i este prim, dar multimplii sai nu sunt nr prime
			for (int j = 2 * i; j <= n; j += i)
				not_prim[j] = true;  // marcam cu true nr neprime
		
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i]
	
	
	Ciur(VALMAX);  // 1 milion O(valmax)
	
	for (int i = 1; i <= n; ++i) // O(n)
		if (prim[a[i]]) // O(1)
			cout << a[i] << ' ';
}
