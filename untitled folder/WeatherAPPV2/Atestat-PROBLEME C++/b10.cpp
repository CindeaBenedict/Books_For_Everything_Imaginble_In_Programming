#include <fstream>
using namespace std;

void PozitiiPare(int n, int v[], int &prim, int &ultim) {
    prim = -1;
    ultim = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            if (prim == -1) {
                prim = i;
            }
            ultim = i;
        }
    }
}

void Sortpq(int n, int v[], int p, int q) {
    for (int i = p; i < q; i++) {
        for (int j = i + 1; j <= q; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    ifstream fin("numere.in");
    ofstream fout("numere.out");
    
    int n, v[100];
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    
    int prim, ultim;
    PozitiiPare(n, v, prim, ultim);
    
    if (prim != -1 && ultim != -1 && prim < ultim) {
        Sortpq(n, v, prim, ultim);
    }
    
    for (int i = 0; i < n; i++) {
        fout << v[i] << " ";
    }
    
    fin.close();
    fout.close();
    return 0;
}