#include <fstream>
using namespace std;

int CifrePare(int n) {
    int result = 0, p = 1;
    while (n > 0) {
        int cifra = n % 10;
        if (cifra % 2 == 0) {
            result = cifra * p + result;
            p *= 10;
        }
        n /= 10;
    }
    return result;
}

int CifreCresc(int n) {
    int prev = 10;
    while (n > 0) {
        int cifra = n % 10;
        if (cifra > prev) {
            return 0;
        }
        prev = cifra;
        n /= 10;
    }
    return 1;
}

int main() {
    ifstream fin("date.in");
    ofstream fout("date.out");
    
    int n, suma = 0;
    
    while (fin >> n) {
        int numar_par = CifrePare(n);
        if (CifreCresc(numar_par) && numar_par != 0) {
            suma += numar_par;
        }
    }
    
    fout << suma;
    
    fin.close();
    fout.close();
    return 0;
}