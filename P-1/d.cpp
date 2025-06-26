#include <bits/stdc++.h>

using namespace std;

int main() {
    int np, valor_total, valor_dividido, resto, ng;
    string nome_doador, nome_recebedor;
    cin >> np;

    map<string, int> grupo;
    vector<string> nomes(np);
    for (int i = 0; i < np;i++) cin >> nomes[i];

    for (int i = 0; i < np; i++) {
        cin >> nome_doador;
        cin >> valor_total >> ng;
        resto = 0;

        if (ng != 0) {
            valor_dividido = valor_total / ng;
            resto = valor_total % ng;
        }

        for (int j = 0; j < ng; j++) {
            cin >> nome_recebedor;
            grupo[nome_recebedor] += valor_dividido;
        }

        grupo[nome_doador] += -valor_total + resto;
    }

    for (int i = 0; i < np; i++) {
        cout << nomes[i] << " " << grupo[nomes[i]] << endl;
    }
}