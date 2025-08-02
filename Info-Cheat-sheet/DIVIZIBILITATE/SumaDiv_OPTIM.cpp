/* Numarul divizorilor unui numar
   Complexitate: < O(sqrt(n)) - subradicalica pe cazul general
   
   n =            2^3     *             3^2 
SumDiv(n): (1 + 2^1 + 2^2 + 2^3) * (1 + 3^1 + 3^2)
          = 1*1 + 1*3 + 3^2 + 2*1 + 2*3 + 2*3^2, ....
          = (2^(3+1) - 1) / (2-1) * (3^(2+1) - 1) / (3-1)
   Suma unei progresii geometrice de ratie x care incepe cu 1
   
   S = 1 + x + x^2 + x^3 + ... + x^n = (x^(n + 1) - 1) / (x - 1)
   
             
   Caz general:
      n = p1^e1 * p2^e2 * ... * pk^ek
      
      
      SumaDiv(n) = (p1^(e1-1) - 1) / (p1-1) * ...* ((pk^(ek-1) - 1) / (pk-1))
       
      F = (p^(e + 1) - 1) / (p - 1)
*/   
#include <iostream>
using namespace std;

long long SumaDiv(int n)
{
	// F = (p^(e + 1) - 1) / (p - 1)
	long long sd = 1;
	long long F = 1;
	
	int p = 2, e = 0;
	while (n != 1)
	{
		e = 0;
		F = 1;
		while (n % p == 0)
		{
			e++;
			n /= p;
			F *= p;
		}                   // F = p^e
		
		if (e)
		{
			 F *= p;         // F = p^(e + 1)
			 F--;            // F = p^(e + 1) - 1
			 F /= (p - 1);   // F = (p^(e + 1) - 1) / (p - 1)
			 sd *= F;
		}
			
		p++;
		if (p * p > n)
			p = n;
	}
	
	return sd;
}

int main()
{
	int n;
	cin >> n;
	cout << SumaDiv(n);
}
