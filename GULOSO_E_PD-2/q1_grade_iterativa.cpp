#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, num_itens, peso_mochila;
    cin >> N;

    vector<vector<int>> matriz(N + 1, vector<int>(N + 1));
    vector<vector<int>> somas(N + 1, vector<int>(N + 1));
    for (int i = 0; i <= N; i++) {
        somas[0][i] = 0;
        somas[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            somas[i][j] = max(somas[i - 1][j], somas[i][j - 1]) + matriz[i][j];
        }
    }

    cout << somas[N][N] << endl;
}