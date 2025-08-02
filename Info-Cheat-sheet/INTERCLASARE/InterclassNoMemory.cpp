#include <fstream>
using namespace std;

int main()
{  
    int ai, n;
    int bj, m;

    ofstream fout("file.out");
    ifstream fin1("file.in");
    ifstream fin2("file.in");
    fin1 >> n >> m;
    fin1 >> ai;     // citim a[1]
        
    fin2 >> n >> m;
    int x;
    for (int i = 1; i <= n; ++i)  // O(n)
        fin2 >> x;
    
    fin2 >> bj;       // citim b[1]
    
    int i = 1, j = 1;

    while (i <= n && j <= m) // O(n + m)
        if (ai <= bj)
        {
            fout << ai << ' ';
            i++;
            fin1 >> ai;
        }
        else
        {
            fout << bj << ' ';
            j++;
            fin2 >> bj;
        }

    while (i <= n)
    {
        fout << ai << ' ';
        i++;
        fin1 >> ai;
    }
        
    while (j <= m)
    {
        fout << bj << ' ';
        j++; 
        fin2 >> bj;
    }
    
    return 0;
}





