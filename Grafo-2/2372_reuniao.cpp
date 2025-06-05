#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, U, V, W;
    cin >> N >> M;

    vector<vector<int>> distancias(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) distancias[i][i] = 0;

    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;

        distancias[U][V] = min(distancias[U][V], W);
        distancias[V][U] = min(distancias[V][U], W);
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (distancias[i][k] != INF && distancias[k][j] != INF) {
                    distancias[i][j] = min(distancias[i][j], distancias[i][k] + distancias[k][j]);
                }
            }
        }
    }

    int menor_maximo = INF;
    for (int i = 0; i < N; i++) {
        int maximo = -INF;

        for (int j = 0; j < N; j++) {
            if (distancias[i][j] != INF && distancias[i][j] > maximo) maximo = distancias[i][j];
        }

        menor_maximo = min(menor_maximo, maximo);
    }

    cout << menor_maximo << endl;
}

    