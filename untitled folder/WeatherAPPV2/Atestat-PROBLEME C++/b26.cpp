#include <iostream>
#include <fstream>
using namespace std;

bool complementare(int a[201][201], int n, int k1, int k2) {
    for (int i = 1; i <= n; i++)
        if (a[i][k1] == a[i][k2])
            return false;
    return true;
}

int main() {
    ifstream fin("atestat.in");
    int n, m, a[201][201], cnt = 0;
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin >> a[i][j];
    
    for (int j = 2; j <= m; j++)
        if (complementare(a, n, 1, j))
            cnt++;
    
    cout << cnt;
    fin.close();
    return 0;
}