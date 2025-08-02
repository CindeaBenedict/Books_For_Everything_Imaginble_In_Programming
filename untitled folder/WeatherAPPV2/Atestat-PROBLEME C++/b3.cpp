#include <fstream>
using namespace std;

int CifraMax(int n) {
    int max_cifra = 0;
    while (n > 0) {
        int cifra = n % 10;
        if (cifra > max_cifra) {
            max_cifra = cifra;
        }
        n /= 10;
    }
    return max_cifra;
}

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    int n, cifre[10] = {0};
    
    while (fin >> n) {
        int cif = CifraMax(n);
        cifre[cif]++;
    }
    
    int max_count = 0;
    for (int i = 0; i < 10; i++) {
        if (cifre[i] > max_count) {
            max_count = cifre[i];
        }
    }
    
    bool first = true;
    for (int i = 0; i < 10; i++) {
        if (cifre[i] == max_count) {
            if (!first) fout << " ";
            fout << i;
            first = false;
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}