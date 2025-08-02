#include <fstream>
#include <cstring>
using namespace std;

bool este_vocala(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
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
        int vocale_gasite = 0;
        
        for (int i = 0; i < lungime; i++) {
            if (este_vocala(cuvant[i])) {
                vocale_gasite++;
                if (vocale_gasite <= x) {
                    continue;
                }
            }
            fout << cuvant[i];
        }
        
        cuvant = strtok(NULL, " ");
    }
    
    fin.close();
    fout.close();
    return 0;
}