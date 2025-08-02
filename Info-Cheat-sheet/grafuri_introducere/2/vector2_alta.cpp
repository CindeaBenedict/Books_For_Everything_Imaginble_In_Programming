#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main()
{
	vector<int> v(10, -7);   // declar un vector cu 10 elemente. Fiecare elem are val-7
	
	for (int x : v)
		cout << x << ' ';
}

