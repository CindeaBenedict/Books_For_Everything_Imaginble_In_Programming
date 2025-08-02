/* 
 * 	Ciurul lui Eratostene
	Complexitate: O(n)
	Este util cand dorm sa determinam TOATE numerele prime
	din intervalul [1...n]
*/
#include <iostream>
using namespace std;

const int N = 100000;
int a[N];
int n;
/*
 * Sa se det toate enumerele prime din sirul a[] (a[i] <= 1000000)
 * 
 */ 

bool Prim(int n)
{
	// cazuri particulare
	if (n < 2)  return false;   // O(1)
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	
	// daca am ajuns aici, stim ca n este IMPAR
	for (int d = 3; d * d <= n; d += 2)
		if (n % d == 0)
			return false;
			
	return true;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i]
		
	for (int i = 1; i <= n; ++i) // O(n * sqrt(valmax))
		if (Prim(a[i])) // O(sqrt(valmax))
			cout << a[i] << ' ';
}
