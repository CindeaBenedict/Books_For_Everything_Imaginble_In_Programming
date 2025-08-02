// Complexitate: O(sqrt(n))
#include <iostream>
using namespace std;

long long SumDiv(int n)
{
	long long sd = 0;
	int p;   // perechea divizorului d
	
	for (int d = 1; d * d <= n; ++d)
		if (n % d == 0)
		{
			sd += d;
			p = n / d;
			if (p != d) // pt cazul cand n este patrat perfect
				sd += p;
		}
		
	return sd;
}

int main()
{
	int n;
	cin >> n;
	cout << SumDiv(n);
}
