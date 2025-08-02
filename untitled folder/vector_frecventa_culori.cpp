#include <fstream>

using namespace std;

int main()
{
    int n,fr[100]={0},i,val;
    ifstream fin("culori.in");
    ofstream fout("culori.out")
    
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>val;
        fr[val]++;
    }
    
    for(i=1;i<=99;i++)
    {
        while(fr[i]>0)
        {
            fout<<i<<" ";
            fr[i]--;
        }
    }
    return 0;
}
