#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream fin("cuvinte.in");
    ofstream fout("cuvinte.out");
    
    char s[21];
    fin >> s;
    int len = strlen(s);
    
    fout << (len % 2 == 0 ? len / 2 : (len + 1) / 2) << "\n";
    
    for (int i = 0; i <= len / 2; i++) {
        for (int j = i; j < len - i; j++) {
            fout << s[j];
        }
        fout << " ";
    }
    
    fin.close();
    fout.close();
    return 0;
}