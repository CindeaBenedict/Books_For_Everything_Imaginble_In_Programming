#include <fstream>
#include <cstring>
using namespace std;

bool este_consoana(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    int x;
    fin >> x;
    fin.ignore();
    
    char text[256];
    fin.getline(text, 256);
    
    char *cuvant = strtok(text, " ");
    bool primul = true;
    
    while (cuvant != NULL) {
        if (!primul) {
            fout << " ";
        }
        primul = false;
        
        int lungime = strlen(cuvant);
        int consoane_gasite = 0;
        int pozitii[256];
        int count = 0;
        
        for (int i = lungime - 1; i >= 0; i--) {
            if (este_consoana(cuvant[i])) {
                consoane_gasite++;
                if (consoane_gasite <= x) {
                    pozitii[count++] = i;
                    continue;
                }
            }
        }
        
        for (int i = 0; i < lungime; i++) {
            bool skip = false;
            for (int j = 0; j < count; j++) {
                if (i == pozitii[j]) {
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                fout << cuvant[i];
            }
        }
        
        cuvant = strtok(NULL, " ");
    }
    
    fin.close();
    fout.close();
    return 0;
}