#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, I, F;
    cin >> N >> I >> F;

    int numeros[N], num_pares = 0;

    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int soma = numeros[i] + numeros[j];

            if (soma >= I && soma <= F) {
                num_pares++;
            }
        }
    }

    cout << num_pares << endl;
}