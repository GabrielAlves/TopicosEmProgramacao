#include <bits/stdc++.h>

#define endl '\n'
#define VERTICE_INICIAL 1

using namespace std;

int todosVerticesVisitados(vector<bool> visitados, int indice_inicial) {
    for (int i = indice_inicial; i < visitados.size(); i++) {
        if (!visitados[i]) return i;
    }

    return -1;
}

int main() {
    int num_vertices, num_arestas, u, v;
    cin >> num_vertices >> num_arestas;
    vector<vector<int> > grafo(num_vertices + 1); 

    for (int i = 0; i < num_arestas; i++) {
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    vector<bool> visitados(num_vertices  + 1, false);
    
    int indice_inicial = todosVerticesVisitados(visitados, VERTICE_INICIAL);
    bool eh_conectado = true;
    int num_componente = 1;

    while (indice_inicial != -1) {
        queue<int> fila;
        fila.push(indice_inicial);
        set<int> componente;
        componente.insert(indice_inicial);

        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();

            if (visitados[u]) continue;
            visitados[u] = true;

            for (int v : grafo[u]) {
                if (!visitados[v]) {
                    componente.insert(v);
                    fila.push(v);
                }
            }
        }

        indice_inicial = todosVerticesVisitados(visitados, indice_inicial);

        if (indice_inicial != -1) {
            if (eh_conectado) {
                eh_conectado = false;
                cout << "NAO EH CONECTADO" << endl;
            }
        }

        if (!eh_conectado) {
            cout << "Componente " << num_componente << ": ";
            num_componente++;
            for (auto it = componente.begin(); it != componente.end(); it++) {
                cout << *it << " ";
            }

            cout << endl;
        }   
    }

    if (eh_conectado) {
        cout << "EH CONECTADO" << endl;
    }
}