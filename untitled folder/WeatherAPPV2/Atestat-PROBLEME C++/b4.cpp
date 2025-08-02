#include <fstream>
using namespace std;

void Inversez(float v[], int p, int q) {
    while (p < q) {
        float temp = v[p];
        v[p] = v[q];
        v[q] = temp;
        p++;
        q--;
    }
}

void Stergp(float v[], int &n, int p) {
    for (int i = p; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    n--;
}

int main() {
    ifstream fin("numere.in");
    ofstream fout("numere.out");
    
    int n;
    float v[100];
    
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    
    if (n % 2 == 1) {
        Stergp(v, n, n / 2);
    }
    
    int mijloc = n / 2;
    Inversez(v, 0, mijloc - 1);
    Inversez(v, mijloc, n - 1);
    
    for (int i = 0; i < n; i++) {
        fout << v[i] << " ";
    }
    
    fin.close();
    fout.close();
    return 0;
}