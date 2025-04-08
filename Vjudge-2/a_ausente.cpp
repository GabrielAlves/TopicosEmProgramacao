#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<int> numeros(n);

    // i inicia em 1 para podermos testar numero[i] != i em vez de numero[i] != i + 1
    for (int i = 1; i < n; i++) {
        cin >> numeros[i];
    }

    sort(numeros.begin(), numeros.end());

    for (int i = 1; i < n; i++) {
        if (numeros[i] != i) {
            cout << i << endl;
            break;
        }

        // só entra aqui se o último número estiver faltando
        if (i == n - 1) {
            cout << n << endl;
        }
    }
}