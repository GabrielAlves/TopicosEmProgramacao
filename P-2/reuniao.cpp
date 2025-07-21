#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, U, V, W;
    cin >> N >> M;
    vector<vector<int>> distancias(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++) distancias[i][i] = 0;

    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        distancias[U][V] = W;
        distancias[V][U] = W;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (distancias[i][k] != INT_MAX && distancias[k][j] != INT_MAX) {
                    distancias[i][j] = min(distancias[i][j], distancias[i][k] + distancias[k][j]);
                }
            }
        }
    }

    int menor_maximo = INT_MAX;
    for (int i = 0; i < N; i++) {
        int maximo = -INT_MAX;

        for (int j = 0; j < N; j++) {
            if (distancias[i][j] > maximo) maximo = distancias[i][j];
        }

        menor_maximo = min(menor_maximo, maximo);
    }

    cout << menor_maximo << endl;
}