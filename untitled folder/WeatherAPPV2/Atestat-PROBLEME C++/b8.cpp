#include <fstream>
using namespace std;

int EPrim(int x) {
    if (x < 2) return 0;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return 0;
    }
    return 1;
}

int main() {
    ifstream fin("numere.in");
    ofstream fout("numere.out");
    
    int n, frecventa[100] = {0};
    bool exista_prime = false;
    
    while (fin >> n) {
        if (EPrim(n)) {
            frecventa[n]++;
            exista_prime = true;
        }
    }
    
    if (!exista_prime) {
        fout << "Nu exista";
    } else {
        int max_aparitii = 0, numar_max = 0;
        for (int i = 0; i < 100; i++) {
            if (frecventa[i] > max_aparitii) {
                max_aparitii = frecventa[i];
                numar_max = i;
            }
        }
        fout << numar_max << " " << max_aparitii;
    }
    
    fin.close();
    fout.close();
    return 0;
}