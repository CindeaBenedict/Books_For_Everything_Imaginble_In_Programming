#include <iostream>
using namespace std;

/*
 *   3    6    1    5    8    7
 * a[1] a[2] a[3] a[4] a[5] a[6]
 *  st         m   m+1        dr  
 */ 


bool AlternDivImp(int a[], int st, int dr)
{
	if (st == dr) return true;
	
	int m = (st + dr) / 2;
	            
	return a[m] % 2 != a[m + 1] % 2 && AlternDivImp(a, st, m) && AlternDivImp(a, m + 1, dr);
	//return f1(a) && f2(b) && f3(c);        
	//return f1(a) || f2(b) || f3(c);
}

int main()
{
	int a[] = {0, 2, 5, 1, 5, 3, 5, 5, 5, 7, 6};
	

	
}

