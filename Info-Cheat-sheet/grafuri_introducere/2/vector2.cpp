#include <iostream>
#include <vector>
#include <set>
using namespace std;

// :: Scope Resolution Operator (operator de rezolvare a domeniului)
int main()
{
	vector<int> v = {50, 10, 30, 20, 5, 10, 50, 20};
	
	// parcurgeri
	// 1
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << '\n';
	
	// 2
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
	
	// 3
	for ( auto it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
	
	// 4 Range Based for Loop (ciclul for pt intervale)
	for(int x : v)
		cout << x << ' ';
}

