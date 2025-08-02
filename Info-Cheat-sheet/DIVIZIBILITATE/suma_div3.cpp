// Complexitate: O(sqrt(n))
#include <iostream>
using namespace std;

long long SumDiv(int n)
{
	long long sd = 0;
	int d;
	for (d = 1; d * d < n; ++d)
		if (n % d == 0)
		{
			sd += d;
			sd += n / d;
		}
	
	if (d * d == n)  // daca n este patrat perfect
		sd += d;
	
	return sd;
}

int main()
{
	int n;
	cin >> n;
	cout << SumDiv(n);
}
