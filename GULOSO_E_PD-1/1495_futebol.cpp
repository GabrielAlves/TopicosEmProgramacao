#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numero_partidas, gols_compraveis, gols_marcados, gols_sofridos;

    while (cin >> numero_partidas >> gols_compraveis) {
        int pontos = 0;
        priority_queue<int> pq;

        for (int i = 0; i < numero_partidas; i++) {
            cin >> gols_marcados >> gols_sofridos;
            int diferenca = gols_marcados - gols_sofridos;

            if (diferenca > 0) pontos += 3;
            else pq.push(diferenca);
        }

        while (!pq.empty()) {
            int diferenca = pq.top();
            pq.pop();

            // variavel diferenca eh 0 ou negativa por isso "+"
            int minimo = gols_compraveis + diferenca; 

            // Eu consigo no máximo chegar a um empate
            if (minimo == 0) {
                pontos++;
                gols_compraveis += diferenca;
            }

            // Eu consigo uma vitória. Comprar apenas um gol além do empate
            else if (minimo > 0) {
                gols_compraveis += (diferenca - 1);
                pontos += 3;
            }
        }

        cout << pontos << endl;
    }
    
}