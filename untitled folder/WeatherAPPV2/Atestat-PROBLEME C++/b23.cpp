#include <fstream>
#include <iostream>
using namespace std;

int nrpare_p(int n, int a[][100]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] % 2 == 0) {
            count++;
        }
    }
    return count > 0 ? count : -1;
}

int nrpare_s(int n, int a[][100]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][n - 1 - i] % 2 == 0) {
            count++;
        }
    }
    return count > 0 ? count : -1;
}

int main() {
    ifstream fin("matrice.in");
    
    int n, a[100][100];
    fin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }
    
    int pare_p = nrpare_p(n, a);
    int pare_s = nrpare_s(n, a);
    
    int impare_p = pare_p == -1 ? n : n - pare_p;
    int impare_s = pare_s == -1 ? n : n - pare_s;
    
    int total_impare = impare_p + impare_s;
    
    if (total_impare == 0) {
        cout << "nu exista";
    } else {
        cout << total_impare;
    }
    
    fin.close();
    return 0;
}