#include <fstream>
using namespace std;

ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");

const int N = 101;
int a[N][N];
int n;    // noduri, muchii

void CitesteGraf();
void ScrieMatrAdiacenta(); 


int main()
{
    CitesteGraf();
    ScrieMatrAdiacenta();
    
    return 0;
}

void CitesteGraf()
{
    int x, y;
    while (fin >> x >> y)
    {          
        a[x][y] = 1;
        a[y][x] = 1;
        if (x > n)
            n = x;
        if (y > n)
            n = y;
    }
}

void ScrieMatrAdiacenta()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << ' ';
        fout << '\n';
    }
}













