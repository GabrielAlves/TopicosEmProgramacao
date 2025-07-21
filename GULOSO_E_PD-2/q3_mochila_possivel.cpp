#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, num_itens, peso_mochila;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num_itens >> peso_mochila;

        vector<int> pesos(num_itens);

        for (int j = 0; j < num_itens; j++) {
            cin >> pesos[j];
        }

        vector<bool> possivel(peso_mochila + 1, false);
        possivel[0] = true;
        for (int j = 0; j < num_itens; j++) {
            for (int k = peso_mochila; k >= 0; k--) {
                if (possivel[k] && k + pesos[j] <= peso_mochila) possivel[k + pesos[j]] = true;
            }
        }

        for (int j = 0; j <= peso_mochila; j++) {
            if (possivel[j]) cout << j << " ";
        }
    }
}