#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

void dfs(const vector<vector<int>> &grafo, vector<bool> &arvores_visitadas, int u) {
    arvores_visitadas[u] = true;

    for (int v : grafo[u]) {
        if (!arvores_visitadas[v]) dfs(grafo, arvores_visitadas, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, D, X, Y;
    cin >> N >> D;
    
    vector<int> x(N);
    vector<int> y(N);

    
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;

        x[i] = X;
        y[i] = Y;
    }

    vector<vector<int>> grafo(N);
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int distancia = hypot(x[i] - x[j], y[i] - y[j]);

            if (distancia <= D) {
                grafo[i].push_back(j);
                grafo[j].push_back(i);
            }
        }
    }
    vector<bool> arvores_visitadas(N, false);

    dfs(grafo, arvores_visitadas, 0);

    bool consegue = true;
    for (int i = 0; i < N; i++) {
        if (!arvores_visitadas[i]) {
            consegue = false;
            break;
        } 
    }

    cout << (consegue ? "S" : "N") << endl;
}

    