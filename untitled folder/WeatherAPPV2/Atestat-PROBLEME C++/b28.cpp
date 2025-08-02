#include <fstream>
using namespace std;

int maxim_d(int n, int a[101][101]) {
    int max_par = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i][i] % 2 == 0 && a[i][i] > max_par)
            max_par = a[i][i];
        if (a[i][n-i+1] % 2 == 0 && a[i][n-i+1] > max_par)
            max_par = a[i][n-i+1];
    }
    return max_par;
}

int main() {
    ifstream fin("matrice.in");
    ofstream fout("matrice.out");
    int n, a[101][101];
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> a[i][j];
    
    int max_par = maxim_d(n, a);
    if (max_par == -1) {
        fout << "tablou nemodificat";
        return 0;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && i != n-j+1 && a[i][j] % 2 != 0)
                a[i][j] = max_par;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            fout << a[i][j] << " ";
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}