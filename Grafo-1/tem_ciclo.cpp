#include <bits/stdc++.h>

#define endl '\n'
#define VERTICE_INICIAL 1

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
    vector<bool> visitados(num_vertices + 1, false);

    fila.push(VERTICE_INICIAL);
    int ultimo_visitado = -1;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        if (visitados[u]) continue;
        visitados[u] = true;

        for (int v : grafo[u]) {
            if (!visitados[v]) {
                fila.push(v);
            }

            if (visitados[v] && v != ultimo_visitado) {
                cout << "Tem ciclo" << endl;
                return 0;
            }
        }   

        ultimo_visitado = u;
    }

    cout << "Nao tem ciclo" << endl;

}