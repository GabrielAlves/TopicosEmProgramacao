#include <bits/stdc++.h>

using namespace std;

int main() {
    int E, N, T, fonte, amigo;
    cin >> E;

    vector<vector<int>> grafo(E);
    for (int i = 0; i < E; i++) {
        cin >> N;
        
        for (int j = 0; j < N; j++) {
            cin >> amigo;
            grafo[i].push_back(amigo);
        }
    }
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> fonte;
        int dia = 1;
        
        queue<pair<int, int>> fila;
        fila.push({dia, fonte});
        
        vector<int> boom_diarios(E + 1, 0);
        vector<bool> visitados(E, false);
        visitados[fonte] = true;
        int boom_maximo = 0, dia_boom;
        
        while (!fila.empty()) {
            int dia = fila.front().first;
            int u = fila.front().second;
            fila.pop();

            for (int v : grafo[u]) {
                if (!visitados[v]) {
                    visitados[v] = true;
                    fila.push({dia + 1, v});
                    boom_diarios[dia]++;

                    if (boom_diarios[dia] > boom_maximo) {
                        boom_maximo = boom_diarios[dia];
                        dia_boom = dia;
                    }
                }
            }
        }

        if (boom_maximo == 0) {
            cout << 0 << endl;
        }

        else {
            cout << boom_maximo << " " << dia_boom << endl;
        }
    } 
}