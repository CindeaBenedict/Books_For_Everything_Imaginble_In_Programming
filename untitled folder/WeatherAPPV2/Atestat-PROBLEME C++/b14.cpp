#include <fstream>
#include <cstring>
using namespace std;

bool este_consoana(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main() {
    ifstream fin("cuvant.in");
    ofstream fout("numar.out");
    
    char s[31];
    fin >> s;
    int len = strlen(s);
    
    if (len > 17) {
        fout << "Imposibil";
        return 0;
    }
    
    bool exista_consoane = false;
    for (int i = 0; i < len; i++) {
        if (este_consoana(s[i])) {
            exista_consoane = true;
            break;
        }
    }
    
    if (!exista_consoane) {
        fout << "Imposibil";
        return 0;
    }
    
    for (int i = 0; i < len; i++) {
        if (este_consoana(s[i])) {
            int poz = (i + 1) % 10;
            fout << poz;
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}