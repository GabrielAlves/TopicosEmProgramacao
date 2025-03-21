#include <bits/stdc++.h>

using namespace std;

int selecionar_vertice(vector<int> dist, vector<int> vertices_restantes) {
    int menor_dist = INT_MAX;
    int v_menor_dist = -1;

    for (auto vertice : vertices_restantes) {
        if (dist[vertice] < menor_dist) {
            menor_dist = dist[vertice];
            v_menor_dist = vertice;
        }
    }

    return v_menor_dist;
}

bool verificar_vertice(vector<int> vertices_restantes, int vertice) {
    for (auto v : vertices_restantes) {
        if (v == vertice) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num_ilhas, num_cabos, u, v, ping, servidor;
    cin >> num_ilhas >> num_cabos;
    vector<vector<pair<int, int>>> grafo(num_ilhas);
    

    for (int i = 0; i < num_cabos; i++) {
        cin >> u >> v >> ping;
        grafo[u - 1].push_back(make_pair(v - 1, ping));
        grafo[v - 1].push_back(make_pair(u - 1, ping));
    }

    cin >> servidor;
    

    vector<int> dist(num_ilhas, INT_MAX);
    vector<int> vertices_restantes(num_ilhas);
    for (int i = 0; i < num_ilhas; i++) {
        vertices_restantes[i] = i;
    }

    dist[servidor - 1] = 0;

    int i = 0;
    while (vertices_restantes.size() != 0) {
        int u = selecionar_vertice(dist, vertices_restantes);
        int distancia = dist[u];

        vertices_restantes.erase(find(vertices_restantes.begin(), vertices_restantes.end(), u));

        for (auto par : grafo[u]) {
                int v = par.first;
                int d = par.second;
                if (verificar_vertice(vertices_restantes, v)) {
                    int alt = dist[u] + d;
    
                    if (alt < dist[v]) {
                        dist[v] = alt;
                    }
                }
        }
    }

    int maior_ping = INT_MIN, menor_ping = INT_MAX;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] != 0) {
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