#include <fstream>
using namespace std;

void interschimbC(int a[201][201], int n, int k1, int k2) {
    for (int i = 1; i <= n; i++) {
        int temp = a[i][k1];
        a[i][k1] = a[i][k2];
        a[i][k2] = temp;
    }
}

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    int n, m, a[201][201], min_val = 1e9, max_val = -1e9, col_min = 1, col_max = 1;
    fin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            fin >> a[i][j];
            if (a[i][j] < min_val) {
                min_val = a[i][j];
                col_min = j;
            }
            if (a[i][j] > max_val) {
                max_val = a[i][j];
                col_max = j;
            }
        }
    
    if (col_min != col_max)
        interschimbC(a, n, col_min, col_max);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            fout << a[i][j] << " ";
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}