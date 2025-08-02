// Complexitate: O(sqrt(n))
#include <iostream>
using namespace std;

long long SumDiv(int n)
{
	long long sd = 0;
		
	for (int d = 1; d * d <= n; ++d)
		if (n % d == 0)
		{
			sd += d;
			if (d * d != n) // pt cazul cand n este patrat perfect
				sd += n / d;
		}
		
	return sd;
}

int main()
{
	int n;
	cin >> n;
	cout << SumDiv(n);
}
