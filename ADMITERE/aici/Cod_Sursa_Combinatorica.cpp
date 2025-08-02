#include <iostream>
using namespace std;

/*

    Implementarea functilor Matematice in Informatica
    -> Combinatorica

    1. Permutari

        P(n) = n! -> functia de permutari = functia de factorial
    ____________________________________________________

    2. Aranjamente

        A(n, k) = n! / (n-k)!
        A(n, k) = P(n) / P(n-k)

        A(100, 1) = 100! / 99! = 100
        A(n, k) = n! / (n-k)! = 1 * 2 * 3 * ... * n / (1 * 2 * ... * (n-k))
                = (n - k + 1) * (n - k + 2) * (n - k + 3) * ... * n
    _____________________________________________________

    3. Combinari

        C(n, k) = n! / (k! * (n-k)!)
        C(n, k) = A(n, k) / P(k)

        C(100, 99) = A(100, 99) / P(99) = 100! / 99! = 100

        C(n, k) = C(n-1, k) + C(n-1, k-1);

        1
        1 1
        1 2 1
        1 3 3 1
        1 4 6 4 1
        ....

*/

int permutari(int n){
    if(n <= 1)
        return 1;
    return n * permutari(n-1);
}

int permutari1(int n){
    int prod = 1;
    for(int i = 2; i <= n; ++i)
        prod *= i;
    return prod;
}

int aranjamente(int n, int k){
    return permutari(n) / permutari1(n-k);
}

int aranjamente1(int n, int k){
    int prod = 1;
    for(int i = n - k + 1; i <= n; ++i)
        prod *= i;
    return prod;
}

int aranjamente2(int n, int k){
    if(k == 0)
        return 1;
    return (n - k + 1) * aranjamente2(n, k - 1);
}

int combinari(int n, int k){
    return aranjamente1(n, k) / permutari1(k);
}

int combinari1(int n, int k){
    if(k == 0 || n == k)
        return 1;
    return combinari1(n-1, k) + combinari1(n-1, k-1);
}

int main(){

    int n, k;
    cin >> n >> k;

    cout << combinari1(n, k);

    return 0;
}