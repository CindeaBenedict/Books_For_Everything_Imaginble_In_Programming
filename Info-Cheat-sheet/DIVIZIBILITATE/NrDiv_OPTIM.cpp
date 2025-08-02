/* Numarul divizorilor unui numar
   Complexitate: < O(sqrt(n)) - subradicalica pe cazul general
   
   n =            2^3     *       3^2 
   Div(n): (1, 2^1, 2^2, 2^3) * (1, 3^1, 3^2)
          = 1*1, 1*3, *3^2, 2*1, 2*3, 2*3^2, ....
              (3 + 1)  * (2 + 1) = 12
              
   Caz general:
      n = p1^e1 * p2^e2 * ... * pk^ek
      
      NrDiv(n) = (e1 + 1) * (e2 + 1) * ... * (ek + 1)
       
*/   
#include <iostream>
using namespace std;

int NrDiv(int n)
{
	int nd = 1;
	
	int p = 2, e = 0;
	while (n != 1)
	{
		e = 0;
		while (n % p == 0)
		{
			e++;
			n /= p;
		}
		
		if (e) 
			nd *= (e + 1);
			
		p++;
		if (p * p > n)
			p = n;
	}
	
	return nd;
}

int main()
{
	int n;
	cin >> n;
	cout << NrDiv(n);
}
