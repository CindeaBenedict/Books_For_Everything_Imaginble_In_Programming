#include <fstream>
using namespace std;

void InserezP(int &n, int v[], int p, int val) {
    for (int i = n; i >= p; i--) {
        v[i] = v[i - 1];
    }
    v[p - 1] = val;
    n++;
}

int SumaCifre(int x) {
    int suma = 0;
    while (x != 0) {
        suma += x % 10;
        x /= 10;
    }
    return suma;
}

int main() {
    ifstream fin("numere.in");
    ofstream fout("numere.out");
    
    int n, v[200];
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    
    for (int i = 0; i < 2 * n; i += 2) {
        int suma = SumaCifre(v[i]);
        InserezP(n, v, i + 2, suma);
    }
    
    for (int i = 0; i < n; i++) {
        fout << v[i] << " ";
    }
    
    fin.close();
    fout.close();
    return 0;
}