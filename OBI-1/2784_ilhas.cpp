#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num_ilhas, num_cabos, u, v, ping, servidor;
    cin >> num_ilhas >> num_cabos;
    vector<vector<pair<int, int>>> grafo(num_ilhas + 1);

    for (int i = 1; i <= num_cabos; i++) {
        cin >> u >> v >> ping;
        grafo[u].push_back(make_pair(v, ping));
        grafo[v].push_back(make_pair(u, ping));
    }

    cin >> servidor;
    
    priority_queue<pair<int, int>> fila;
    vector<bool> visitados(num_ilhas + 1, false);
    vector<int> dist(num_ilhas + 1, INT_MAX);
    dist[servidor] = 0;
    
    for (int i = 1; i <= num_ilhas; i++) {
        if (i == servidor) fila.push({0, i});
        else fila.push({INT_MIN, i});
    }

    while (!fila.empty()) {
        auto elem = fila.top();
        fila.pop();

        int u = elem.second;

        if (visitados[u]) continue;
        
        visitados[u] = true;

        for (auto par : grafo[u]) {
            int v = par.first;
            int peso_v = par.second;

            if (!visitados[v]) {
                int alt = dist[u] + peso_v;

                if (alt < dist[v]) {
                    dist[v] = alt;
                    fila.push({-dist[v], v});
                }
            }
        }
    }

    int maior_ping = INT_MIN, menor_ping = INT_MAX;
    for (int i = 1; i <= num_ilhas; i++) {
        if (i != servidor) {
            if (dist[i] < menor_ping) {
                menor_ping = dist[i];
            }

            if (dist[i] > maior_ping) {
                maior_ping = dist[i];
            }
        }
    }
    
    cout << maior_ping - menor_ping << "\n";
}