// Matrice cu STL
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// type alias-uri
using VI  = vector<int>;
using VVI = vector<VI>;

int main()
{
	VVI a; // vector vid
	int n, m;
	cin >> n >> m;
	
	a = VVI(n, VI(m)); // aici se creaza matricea
/*	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = i + j;
*/			
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	
}

