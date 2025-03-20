#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, A, distancia;
    cin >> N;
    int predios[N];

    for (int i = 0; i < N; i++) {
        cin >> predios[i];
    }

    int maior_distancia = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            distancia = predios[i] + (j - i) + predios[j];

            if (distancia > maior_distancia) {
                maior_distancia = distancia;
            }
            }

        }
    cout << maior_distancia << endl;

    }