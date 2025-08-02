#include <fstream>
using namespace std;

int Cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int Cmmmc(int a, int b) {
    return a * b / Cmmdc(a, b);
}

int main() {
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    
    int n, cmmdc_total, cmmmc_total;
    bool first = true;
    
    while (fin >> n) {
        if (first) {
            cmmdc_total = n;
            cmmmc_total = n;
            first = false;
        } else {
            cmmdc_total = Cmmdc(cmmdc_total, n);
            cmmmc_total = Cmmmc(cmmmc_total, n);
        }
    }
    
    fout << cmmdc_total << "\n" << cmmmc_total;
    
    fin.close();
    fout.close();
    return 0;
}