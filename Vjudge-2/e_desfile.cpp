#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, valor;

    cin >> n;

    while (n != 0) {
        int ordem = 1;
        stack<int> fora_de_ordem;

        for (int i = 0; i < n; i++) {
            cin >> valor;

            if (valor != ordem) {
                fora_de_ordem.push(valor);
            }

            else {
                ordem++;
            }
        }

        int ultimo = 0;
        while (!fora_de_ordem.empty() && fora_de_ordem.top() > ultimo) {
            ultimo = fora_de_ordem.top();
            fora_de_ordem.pop();
        }

        cout << (fora_de_ordem.empty() ? "yes" : "no") << endl;

        cin >> n;
    }
}