#include <fstream>
#include <cstring>
using namespace std;

bool este_vocala(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    char text[256];
    fin.getline(text, 256);
    
    char text_decodificat[256];
    int index = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        text_decodificat[index++] = text[i];
        if (este_vocala(text[i])) {
            i += 2;
        }
    }
    text_decodificat[index] = '\0';
    
    fout << text_decodificat;
    
    fin.close();
    fout.close();
    return 0;
}