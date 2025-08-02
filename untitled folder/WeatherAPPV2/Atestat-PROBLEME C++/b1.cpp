#include <fstream>
using namespace std;

int Concatenare(int a, int b) {
    int p = 1;
    while (p <= b)
        p *= 10;
    return a * p + b;
}

int main() {
    ifstream fin("numere.in");
    ofstream fout("numere.out");
    
    int n, a, b;
    fin >> n;
    fin >> a;
    
    for (int i = 1; i < n; i++) {
        fin >> b;
        int concat1 = Concatenare(a, b);
        int concat2 = Concatenare(b, a);
        fout << (concat1 > concat2 ? concat1 : concat2) << " ";
        a = b;
    }
    
    fin.close();
    fout.close();
    return 0;
}