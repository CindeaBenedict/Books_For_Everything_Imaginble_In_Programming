#include <iostream>
#include <fstream>
using namespace std;

int numarare(int x[101][101], int n, int p) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (x[i][p] != 0)
            cnt++;
    return cnt;
}

bool toateNule(int x[101][101], int n, int p) {
    for (int j = 1; j <= n; j++)
        if (x[p][j] != 0)
            return false;
    return true;
}

int main() {
    ifstream fin("atestat.in");
    int n, x[101][101];
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> x[i][j];
    
    for (int i = 1; i <= n; i++) {
        if (toateNule(x, n, i)) {
            for (int j = 1; j <= n; j++)
                x[i][j] = numarare(x, n, j);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
    
    fin.close();
    return 0;
}