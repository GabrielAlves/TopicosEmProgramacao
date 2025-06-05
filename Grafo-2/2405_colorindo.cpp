#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, X, Y, K;
    cin >> N >> M >> X >> Y >> K;
    
    vector<vector<int>> grafo(N + 1, vector<int>(M + 1, 0));
    queue<pair<int, int>> fila; 
    grafo[X][Y] = 1;
    fila.push({X, Y});

    for (int i = 0; i < K; i++) {
        cin >> X >> Y;
        grafo[X][Y] = 1;
    }

    int quadrados_pintados = 1;
    vector<pair<int, int>> movimentos = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    while (!fila.empty()) {
        pair<int, int> quadrado = fila.front();
        int i = quadrado.first;
        int j = quadrado.second;

        fila.pop();

        for (auto mov : movimentos) {
            int ni = i + mov.first;
            int nj = j + mov.second;

            if (ni >= 1 && ni < N + 1 && nj >= 1 && nj < M + 1) {
                if (grafo[ni][nj] == 0) {
                    grafo[ni][nj] = 1;
                    quadrados_pintados++;
                    fila.push({ni, nj});
                }
            }
        }
    }   

    cout << quadrados_pintados << endl;
}