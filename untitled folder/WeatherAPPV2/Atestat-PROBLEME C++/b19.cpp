#include <fstream>
#include <cstring>
using namespace std;

bool este_vocala(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    char text[51];
    fin.getline(text, 51);
    
    char text_modificat[151];
    int index = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        text_modificat[index++] = text[i];
        if (este_vocala(text[i])) {
            text_modificat[index++] = text[i] + 1;
            text_modificat[index++] = text[i] + 2;
        }
    }
    text_modificat[index] = '\0';
    
    fout << text_modificat;
    
    fin.close();
    fout.close();
    return 0;
}