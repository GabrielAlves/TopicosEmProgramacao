#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, i, j;
    cin >> N >> M;

    vector<vector<int>> grafo(N + 1);

    for (int k = 0; k < M; k++) {
        cin >> i >> j;
        grafo[i].push_back(j);
        grafo[j].push_back(i);
    }
    

    vector<bool> visitados(N + 1, false);
    int num_times = 0;

    queue<int> fila;
    for (int i = 1; i <= N; i++) {
        if (!visitados[i]) {
            fila.push(i);

            while (!fila.empty()) {
                int u = fila.front();
                fila.pop();

                visitados[u] = true;

                for (int v : grafo[u]) {
                    if (!visitados[v]) fila.push(v);
                }
            }

            num_times++;
        }
    }

    cout << num_times << endl;
}