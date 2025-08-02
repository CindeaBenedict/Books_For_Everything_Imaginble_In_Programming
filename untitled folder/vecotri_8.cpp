#include <iostream>
#include <fstream>

using namespace std;

int main()
{   ifstream fin("numere.txt");
    int n,fr[100]={0},i,nr;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>nr;
        fr[nr]++;
    }
    for(i=0;i<=99;i++)
        while(fr[i]>0)
    {
        cout<<i<<' ';
        fr[i]--;
    }
    return 0;
}