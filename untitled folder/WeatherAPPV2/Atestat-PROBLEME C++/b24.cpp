#include <fstream>
using namespace std;

int suma(int x[11][11], int n, int p) {
    int s = 0;
    for (int j = 1; j <= n; j++)
        s += x[p][j];
    return s;
}

int main() {
    ifstream fin("matrice.in");
    ofstream fout("matrice.out");
    
    int n, x[11][11];
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> x[i][j];
    
    int max_sum = -1;
    for (int i = 1; i <= n; i++) {
        int current = suma(x, n, i);
        if (current > max_sum)
            max_sum = current;
    }
    
    for (int i = 1; i <= n; i++)
        if (suma(x, n, i) == max_sum)
            fout << i << " ";
    
    fin.close();
    fout.close();
    return 0;
}