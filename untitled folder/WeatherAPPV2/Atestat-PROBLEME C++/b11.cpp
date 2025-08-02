#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream fin("sufixe.in");
    ofstream fout("sufixe.out");
    
    char s[21];
    fin >> s;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        fout << (s + i) << " ";
    }
    fout << "\n" << len;
    
    fin.close();
    fout.close();
    return 0;
}