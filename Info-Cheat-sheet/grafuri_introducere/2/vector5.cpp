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
	
	// matricea se creaza run-time
	a = VVI(n + 1, VI(m + 1)); // aici se creaza matricea
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = i + j;
			
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	
}

