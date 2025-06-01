#include <bits/stdc++.h>

#define endl '\n'
#define VERTICE_INICIAL 1
#define COR_INICIAL 0

using namespace std;

int main() {
    int num_vertices, num_arestas, u, v;
    cin >> num_vertices >> num_arestas;
    vector<vector<int>> grafo(num_vertices + 1); 

    for (int i = 0; i < num_arestas; i++) {
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    queue<int> fila;
    fila.push(VERTICE_INICIAL);
    vector<bool> visitados(num_vertices + 1, false);
    map<int, int> cores;
    cores[VERTICE_INICIAL] = COR_INICIAL;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        if (visitados[u]) continue;
        visitados[u] = true;

        for (int v : grafo[u]) {
            if (!visitados[v]) {
                fila.push(v);
                cores[v] = cores[u] == 0 ? 1 : 0;
            }

            if (cores[v] == cores[u]) {
                cout << "Nao eh bipartido" << endl;
                return 0;
            }
        }
    }

    cout << "Eh bipartido" << endl;

}