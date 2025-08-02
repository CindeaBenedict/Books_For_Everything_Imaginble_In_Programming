#include <fstream>
using namespace std;

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    int n, k;
    fin >> n >> k;
    
    int a[21][21];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
        }
    }
    
    bool linii_comune[21] = {false};
    
    for (int j = 1; j <= n; j++) {
        int element = a[k][j];
        for (int i = 1; i <= n; i++) {
            if (i != k) {
                for (int l = 1; l <= n; l++) {
                    if (a[i][l] == element) {
                        linii_comune[i] = true;
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (linii_comune[i] && i != k) {
            fout << i << " ";
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}