#include <fstream>
using namespace std;

ifstream fin("listavecini.in");
ofstream fout("listavecini.out");

const int N = 101;
int a[N][N];
int g[N]; // gradele nodurilor
int n;    // noduri

void CitesteGraf();
void ScrieVecini(); 

int main()
{
    CitesteGraf();
    ScrieVecini();
    
    return 0;
}

void CitesteGraf()
{
    fin >> n;
    int x, y;
               
    while (fin >> x >> y)
    {     
        if (a[x][y] == 0)
        {
            g[x]++;
            g[y]++;
            a[x][y] = 1;
            a[y][x] = 1;
        }
    }
}

void ScrieVecini()
{
    for (int i = 1; i <= n; ++i)
    {
        fout << g[i] << ' ';
        for (int j = 1; j <= n; ++j)
            if (a[i][j] == 1)
                fout << j << ' ';
        fout << '\n';
    }
}













