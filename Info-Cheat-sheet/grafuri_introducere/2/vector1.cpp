#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;  // declar un vector vid
	//cout << sizeof(v) << '\n';
	cout << v.size() << '\n';
	
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	cout << v.size() << '\n';
	
	v.pop_back();
	cout << v.size() << '\n';
}

