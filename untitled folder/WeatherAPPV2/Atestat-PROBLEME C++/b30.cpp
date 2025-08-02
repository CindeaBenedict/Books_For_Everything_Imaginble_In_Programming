#include <fstream>
#include <algorithm>
using namespace std;

struct Elev {
    string nume, prenume;
    int total, motivate, nota;
};

bool cmp(Elev a, Elev b) {
    if (a.nota != b.nota) return a.nota > b.nota;
    if (a.nume != b.nume) return a.nume < b.nume;
    return a.prenume < b.prenume;
}

int main() {
    ifstream fin("elevi.in");
    ofstream fout("elevi.out");
    int n;
    fin >> n;
    Elev e[100];
    
    for (int i = 0; i < n; i++) {
        fin >> e[i].nume >> e[i].prenume >> e[i].total >> e[i].motivate;
        int nemotivate = e[i].total - e[i].motivate;
        if (nemotivate > 50) e[i].nota = 4;
        else e[i].nota = 10 - nemotivate / 10;
    }
    
    sort(e, e+n, cmp);
    
    for (int i = 0; i < n; i++)
        fout << e[i].nume << " " << e[i].prenume << " " << e[i].nota << endl;
    
    fin.close();
    fout.close();
    return 0;
}