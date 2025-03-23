#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<vector<char>> matriz(N, vector<char>(M));
    queue<pair<int, int>> fila;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz[i][j];

            if (matriz[i][j] == 'o') {
                fila.emplace(i, j);
            }
        }
    }

    while (!fila.empty()) {
        pair<int, int> pos = fila.front();
        fila.pop();

        int i = pos.first;
        int j = pos.second;

        if (i + 1 < N && matriz[i + 1][j] == '.') {
            matriz[i + 1][j] = 'o';
            fila.emplace(i + 1, j);
        }

        if (i + 1 < N && matriz[i + 1][j] == '#') {
            if (j + 1 < M && matriz[i][j + 1] == '.') {
                matriz[i][j + 1] = 'o';
                fila.emplace(i, j + 1);
            }

            if (j - 1 >= 0 && matriz[i][j - 1] == '.') {
                matriz[i][j - 1] = 'o';
                fila.emplace(i, j -1);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j];
        }
        cout << "\n";
    }

    
}