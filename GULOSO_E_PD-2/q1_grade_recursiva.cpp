#include <bits/stdc++.h>

using namespace std;

int soma(vector<vector<int>> matriz, vector<vector<int>> &somas, int i, int j, int N) {
    if (i == 0 || j == 0) return 0;
    if (somas[i][j]) return somas[i][j];
    somas[i][j] = max(soma(matriz, somas, i, j - 1, N), soma(matriz, somas, i - 1, j, N)) + matriz[i][j];
    
    if (j < N) soma(matriz, somas, i, j + 1, N);
    if (i < N) soma(matriz, somas, i + 1, j, N);
    
    return somas[i][j];

}

int main() {
    int N, num_itens, peso_mochila;
    cin >> N;

    vector<vector<int>> matriz(N + 1, vector<int>(N + 1));
    vector<vector<int>> somas(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> matriz[i][j];
        }
    }

    soma(matriz, somas, 1, 1, N);
    cout << somas[N][N] << endl;
}