#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, num_itens, peso_mochila;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num_itens >> peso_mochila;

        vector<int> pesos(num_itens);
        vector<int> valores(num_itens);

        priority_queue<pair<int, int>> pq;
        for (int j = 0; j < num_itens; j++) {
            cin >> pesos[j] >> valores[j];
            pq.push({(double) valores[j] / pesos[j], j});
        }

        int valor_maximo = 0;
        while (!pq.empty() && peso_mochila != 0) {
            pair<int, int> par = pq.top();
            pq.pop();

            double razao = par.first;
            int j = par.second;

            if (pesos[j] <= peso_mochila) {
                valor_maximo += valores[j];
                peso_mochila -= pesos[j];
            }

            else {
                valor_maximo += razao * peso_mochila;
                peso_mochila = 0;
            }
        }

        cout << valor_maximo << endl;
    }
}