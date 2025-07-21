#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, num_itens, peso_mochila;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num_itens >> peso_mochila;

        vector<int> pesos(num_itens);
        vector<int> valores(num_itens);

        for (int j = 0; j < num_itens; j++) {
            cin >> pesos[j] >> valores[j];
        }

        vector<int> somas(peso_mochila + 1, -1);
        somas[0] = 0;
        for (int j = 0; j < num_itens; j++) {
            for (int k = peso_mochila; k >= 0; k--) {
                if (somas[k] != -1 && k + pesos[j] <= peso_mochila) somas[k + pesos[j]] = max(somas[k + pesos[j]], somas[k] + valores[j]);
            }
        }

        int maximo = INT_MIN;
        for (int j = 1; j <= peso_mochila; j++) {
            if (maximo < somas[j]) maximo = somas[j];
        }

        cout << maximo << endl;
    }
}