#include <fstream>
using namespace std;

void interschimbL(int a[][200], int m, int k1, int k2) {
    for (int j = 0; j < m; j++) {
        int temp = a[k1][j];
        a[k1][j] = a[k2][j];
        a[k2][j] = temp;
    }
}

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    int n, m, a[200][200];
    fin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> a[i][j];
        }
    }
    
    int min_val = a[0][0], max_val = a[0][0];
    int linie_min = 0, linie_max = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] < min_val) {
                min_val = a[i][j];
                linie_min = i;
            }
            if (a[i][j] > max_val) {
                max_val = a[i][j];
                linie_max = i;
            }
        }
    }
    
    if (linie_min != linie_max) {
        interschimbL(a, m, linie_min, linie_max);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << a[i][j] << " ";
        }
        fout << "\n";
    }
    
    fin.close();
    fout.close();
    return 0;
}