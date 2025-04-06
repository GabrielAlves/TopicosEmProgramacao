#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, valor, soma;
    cin >> n >> soma;
    vector<pair<int, int>> numeros(n);

    for (int i = 0; i < n; i++) {
        cin >> valor;
        numeros[i] = {valor, i + 1};
    }

    sort(numeros.begin(), numeros.end());

    int inicio = 0, fim = n - 1;

    bool achou = false;
    while (inicio < fim) {
        if(numeros[inicio].first + numeros[fim].first == soma) {
            cout << (numeros[inicio].second) << " " << (numeros[fim].second) << endl;
            achou = true;
            break;
        }
        
        if (numeros[inicio].first + numeros[fim].first > soma) {
            fim--;
        }


        else {
            inicio++;
        }
    }

    if (!achou) {
        cout << "IMPOSSIBLE" << endl;
    }


}