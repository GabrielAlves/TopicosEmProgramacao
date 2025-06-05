#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, E, X, Y, H, K;
    cin >> N >> E;

    while (N + E > 0) {
        vector<vector<int>> distancias(N + 1, vector<int>(N + 1, INF));

        for (int i = 1; i <= N; i++) distancias[i][i] = 0;

        for (int i = 0; i < E; i++) {
            cin >> X >> Y >> H;

            // agencias do mesmo territorio, transmissao instantanea
            if (distancias[Y][X] != INF) {
                distancias[X][Y] = 0;
                distancias[Y][X] = 0;
            }

            else {  
                distancias[X][Y] = H;
            }
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (distancias[i][k] != INF && distancias[k][j] != INF) distancias[i][j] = min(distancias[i][j], distancias[i][k] + distancias[k][j]);
                }
            }
        }

        cin >> K;

        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            if (distancias[X][Y] < INF) cout << distancias[X][Y] << endl;
            else cout << "Nao e possivel entregar a carta" << endl;
        }
        cout << endl;
        cin >> N >> E;
    }
    
}