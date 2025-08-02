/* Opeartia modulo, proprietati:
 * 
 * 1. Asociativitate fata de adunare
 * 
 *    (a + b + c) % Mod = ((a + b) % Mod + c) % Mod
 * 
 * 
 * 2. Asociativitate fata de inmultire
 * 
 *    (a * b * c) % Mod = ((a * b) % Mod * c) % Mod
 * 
 * 3. Asociatvitate fata de scadere
 *    vezi exemplele
 *    (a - b) % Mod = (a - b + Mod) % Mod
 * 
 * 4. NU exista asociativitate fata de impartire!
 * 
 *    (a / b) % Mod != (a % Mod) / (b % Mod)
 */ 

#include <iostream>
using namespace std;

const int Mod = 2731;
int main()
{
	int a = 1200, b = 2100;
	
	// var 1 (pt a - b)
	int x = a - b;
	if (x < 0)         // asa
		x += Mod;
		
	// var 2
	
	int y = (a - b + Mod) % Mod;  // sau asa!
	
	cout << x << ' ' << y << ' ';
	
	//cout << (a - b) % Mod;  nu asa!
}




