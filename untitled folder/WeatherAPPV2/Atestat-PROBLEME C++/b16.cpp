#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    char text[101];
    fin.getline(text, 101);
    
    char c;
    fin >> c;
    
    int modificari = 0;
    char text_modificat[201];
    int index = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        text_modificat[index++] = text[i];
        if (text[i] == c) {
            text_modificat[index++] = c;
            modificari++;
        }
    }
    text_modificat[index] = '\0';
    
    fout << modificari << "\n" << text_modificat;
    
    fin.close();
    fout.close();
    return 0;
}