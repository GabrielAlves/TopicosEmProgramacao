#include <bits/stdc++.h>

using namespace std;

int main() {
    int queries, tipo, pontos;
    string nome;
    map<string, int> notas;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> tipo >> nome;

        if (tipo == 1) {
            cin >> pontos;

            notas[nome] += pontos;
        }

        else if (tipo == 2) {
            notas[nome] = 0;
        }

        else {
            cout << notas[nome] << endl;
        }
    }

}