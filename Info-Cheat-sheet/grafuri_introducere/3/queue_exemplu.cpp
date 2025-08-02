#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;

int main()
{
	queue<string> Q; // declar o coada vida
	
	Q.push("Iris");
	Q.push("Mario");
	Q.push("Nicu");
	Q.push("Nelu");
	Q.push("Ana");
	
	while (!Q.empty())
	{
		cout << Q.front() << ' ';
		Q.pop();
	}
}


