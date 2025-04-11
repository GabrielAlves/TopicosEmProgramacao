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

    int inicio = 0, fim = n - 1, meio = (inicio + fim) / 2;
    bool achou = false;
    while (inicio < fim) {
        bool deve_mover_extremidades = (meio - 1 == inicio || meio + 1 == fim);

        if(numeros[inicio].first + numeros[meio].first + numeros[fim].first == soma) {
            cout << (numeros[inicio].second) << " " << (numeros[meio].second) << " " << (numeros[fim].second) << endl;
            achou = true;
            break;
        }
        
        else if (numeros[inicio].first + numeros[meio].first + numeros[fim].first > soma) {
            if (deve_mover_extremidades) fim--;
            else meio--;
        }


        else {
            if (deve_mover_extremidades) inicio++;
            else meio++;
        }

        // so chega aqui se as extremidades foram movidas. Atualiza o meio.
        if (deve_mover_extremidades) {
            meio = (inicio + fim) / 2;
        }
    }

    if (!achou) {
        cout << "IMPOSSIBLE" << endl;
    }


}