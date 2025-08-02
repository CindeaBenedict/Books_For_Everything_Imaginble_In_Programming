#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    int x;
    fin >> x;
    fin.ignore();
    
    char text[256];
    fin.getline(text, 256);
    
    char *cuvant = strtok(text, " ");
    int count = 0;
    char cuvinte_valide[100][256];
    int index = 0;
    
    while (cuvant != NULL) {
        int aparitii_o = 0;
        for (int i = 0; i < strlen(cuvant); i++) {
            if (cuvant[i] == 'o') {
                aparitii_o++;
            }
        }
        
        if (aparitii_o >= 1 && aparitii_o <= x) {
            count++;
            strcpy(cuvinte_valide[index++], cuvant);
        }
        
        cuvant = strtok(NULL, " ");
    }
    
    fout << count << "\n";
    for (int i = 0; i < index; i++) {
        fout << cuvinte_valide[i] << "\n";
    }
    
    fin.close();
    fout.close();
    return 0;
}