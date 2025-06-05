#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    char tabuleiro[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tabuleiro[i][j];
        }
    }
    int K, L, C;
    cin >> K;
    
    map<pair<int, int>, int> ataques_map;
    vector<pair<int, int>> ataques;
    
    for (int i = 0; i < K; i++) {
        cin >> L >> C;
        L--;
        C--;

        if (tabuleiro[L][C] == '#') {
            ataques_map[{L, C}] = 1;
            ataques.push_back({L, C});
        }
    }

    int num_navios_destruidos = 0;
    vector<pair<int, int>> movimentos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto ataque : ataques) {
        if (tabuleiro[ataque.first][ataque.second] == '.') continue;
        tabuleiro[ataque.first][ataque.second] = '.';
        queue<pair<int, int>> fila;
        fila.push(ataque);
        vector<pair<int, int>> navio;

        while (!fila.empty()) {
            pair<int, int> ataque = fila.front();
            fila.pop();

            int i = ataque.first;
            int j = ataque.second;

            navio.push_back({i, j});
            
            for (auto movimento : movimentos) {
                int ni = i + movimento.first;
                int nj = j + movimento.second;

                if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
                    if (tabuleiro[ni][nj] == '#') {
                        tabuleiro[ni][nj] = '.';
                        fila.emplace(ni, nj);
                    }
                }
            }
        }

        bool afundou = true;
        for (pair<int, int> n : navio) {
            if (!ataques_map[{n.first, n.second}]) {
                afundou = false;
                break;
            }
        }

        if (afundou) {
            num_navios_destruidos++;
        }
    }   

    cout << num_navios_destruidos << "\n";
}