#include <iostream>
#include <fstream>

using namespace std;

int main()
{   ifstream fin("bac.in");
    int n,fr[10000]={0},i,nr;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>nr;
        fr[nr]++;
    }
    for(i=0;i<=9999;i++)
        if(fr[i]==1)
           cout<<i<<' ';
    return 0;
}