#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> imagem(N, vector<int>(M));
    vector<vector<int>> uns;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> imagem[i][j];

            // Guarda quais pixels sao escuros para acelerar a busca das manchas
            if (imagem[i][j] == 1) {
                uns.push_back({i, j}); 
            }
        }
    }

    int num_manchas = 0;
    queue<vector<int>> fila;
    for (auto um : uns) {
        int i = um[0];
        int j = um[1];

        if (imagem[i][j] == 1) {
            fila.push(um);

            while (!fila.empty()) {
                int i = fila.front()[0];
                int j = fila.front()[1];
                fila.pop();

                // em cima
                if (i - 1 >= 0 && imagem[i - 1][j] == 1) {
                    imagem[i - 1][j] = 0;
                    fila.push({i - 1, j});
                }

                // em baixo
                if (i + 1 < N && imagem[i + 1][j] == 1) {
                    imagem[i + 1][j] = 0;
                    fila.push({i + 1, j});
                }
            
                // na esquerda
                if (j - 1 >= 0 && imagem[i][j - 1] == 1) {
                    imagem[i][j - 1] = 0;
                    fila.push({i, j - 1});
                }

                // na direita
                if (j + 1 < M && imagem[i][j + 1] == 1) {
                    imagem[i][j + 1] = 0;
                    fila.push({i, j + 1});
                }
            }
            
            num_manchas++;
        }
    }
    
    cout << num_manchas << "\n";
}