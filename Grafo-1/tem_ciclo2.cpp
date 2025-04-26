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
    vector<int> anteriores(num_vertices + 1);
    anteriores[VERTICE_INICIAL] = -1;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        if (visitados[u]) continue;
        visitados[u] = true;

        for (int v : grafo[u]) {
            if (!visitados[v]) {
                fila.push(v);
                anteriores[v] = u;
            }

            // achou um ciclo. 
            if (visitados[v] && v != anteriores[u]) {
                cout << "Tem ciclo" << endl;

                int vertice = u;
                int num_vertices = 0;

                cout << "Vertices do ciclo:";
                // Retorna por onde veio até chegar no nó inicial
                while (vertice != v) {
                    num_vertices++;
                    cout << vertice << " ";
                    vertice = anteriores[vertice];
                }
                
                cout << v;
                num_vertices++;

                cout << endl << "Numero de vertices: " << num_vertices << endl;
                cout << "Numero de arestas: " << (num_vertices - 1) << endl;

                return 0;
            }
        }      
    }

    cout << "Nao tem ciclo" << endl;
}