#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

struct Produs {
    double cantitate, pret, adaos;
};

int main() {
    ifstream fin("vanzari.in");
    int n;
    double total = 0;
    fin >> n;
    Produs p[100];
    
    int max_cant = 0, poz_max = 1;
    for (int i = 0; i < n; i++) {
        fin >> p[i].cantitate >> p[i].pret >> p[i].adaos;
        double pv = p[i].pret * (1 + p[i].adaos/100);
        total += p[i].cantitate * pv;
        
        if (p[i].cantitate > max_cant || 
           (p[i].cantitate == max_cant && p[i].adaos > p[poz_max-1].adaos)) {
            max_cant = p[i].cantitate;
            poz_max = i+1;
        }
    }
    
    cout << fixed << setprecision(2) << total << endl << poz_max;
    fin.close();
    return 0;
}