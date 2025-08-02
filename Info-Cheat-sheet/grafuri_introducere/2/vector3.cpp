// Matrice cu STL
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	vector<vector<int>> a; // vector vid
	int n, m;
	cin >> n >> m;
	
	a = vector<vector<int>>(n, vector<int>(m));
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = i + j;
			
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	
}

