#include <fstream>
using namespace std;

int FactorPutereMax(int n) {
    int max_factor = -1, max_putere = -1;
    
    for (int d = 2; d <= n; d++) {
        if (n % d == 0) {
            int putere = 0;
            while (n % d == 0) {
                putere++;
                n /= d;
            }
            if (putere > max_putere || (putere == max_putere && d > max_factor)) {
                max_putere = putere;
                max_factor = d;
            }
        }
    }
    
    return max_factor;
}

int main() {
    ifstream fin("date.in");
    ofstream fout("date.out");
    
    int n, max_factor = -1;
    int factors[1000];
    int count = 0;
    
    while (fin >> n) {
        int factor = FactorPutereMax(n);
        factors[count++] = factor;
        if (factor > max_factor) {
            max_factor = factor;
        }
    }
    
    for (int i = 0; i < count; i++) {
        fout << factors[i] << " ";
    }
    fout << "\n" << max_factor;
    
    fin.close();
    fout.close();
    return 0;
}