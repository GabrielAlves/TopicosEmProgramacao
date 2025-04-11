#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<int> numeros(N);

    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    int queries, numero;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> numero;

        auto low = lower_bound(numeros.begin(), numeros.end(), numero);

        if (*low == numero) {
            cout << "Yes ";
        }

        else {
            cout << "No ";
        }

        cout << (low - numeros.begin() + 1) << endl;
    }

}