#include <bits/stdc++.h>

using namespace std;

int main() {
    int queries, tipo, numero;
    set<int> numeros;
    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> tipo >> numero;

        if (tipo == 1) {
            numeros.insert(numero);
        }

        else if (tipo == 2) {
            numeros.erase(numero);
        }

        else {
            auto it = numeros.find(numero);

            if (it != numeros.end()) {
                cout << "Yes" << endl;
            }

            else {
                cout << "No" << endl;
            }
        }
    }

}