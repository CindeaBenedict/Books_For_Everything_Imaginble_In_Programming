#include <fstream>
using namespace std;

int CifreDistincte(int n) {
    int cifre[10] = {0};
    while (n > 0) {
        int cifra = n % 10;
        if (cifre[cifra] > 0) {
            return 0;
        }
        cifre[cifra]++;
        n /= 10;
    }
    return 1;
}

int main() {
    ifstream fin("date.in");
    ofstream fout("date.out");
    
    int n, count_distincte = 0, count_nedistincte = 0;
    int distincte[1000], nedistincte[1000];
    
    while (fin >> n) {
        if (CifreDistincte(n)) {
            distincte[count_distincte++] = n;
        } else {
            nedistincte[count_nedistincte++] = n;
        }
    }
    
    if (count_distincte == 0) {
        fout << "Nu exista\n";
    } else {
        for (int i = 0; i < count_distincte; i++) {
            fout << distincte[i] << " ";
        }
        fout << count_distincte << "\n";
    }
    
    if (count_nedistincte == 0) {
        fout << "Nu exista";
    } else {
        for (int i = 0; i < count_nedistincte; i++) {
            fout << nedistincte[i] << " ";
        }
        fout << count_nedistincte;
    }
    
    fin.close();
    fout.close();
    return 0;
}