// Numarul divizorilor unui numar
// Complexitate: O(sqrt(n))
#include <iostream>
using namespace std;

int NrDiv(int n)
{
	int nd = 0;
		
	for (int d = 1; d * d <= n; ++d)
		if (n % d == 0)
		{
			nd++;
			if (d * d != n) // pt cazul cand n este patrat perfect
				nd++;
		}
		
	return nd;
}

int main()
{
	int n;
	cin >> n;
	cout << NrDiv(n);
}
