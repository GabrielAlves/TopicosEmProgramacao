#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, L, C;
    string palavra;

    while (cin >> N >> L >> C) {
        cin.ignore();

        int num_minimo_paginas = 1;
        int contador_linhas = 1;
        int contador_caracteres = C;

        for (int i = 0; i < N; i++) {
            cin >> palavra;

            // Contabiliza o " " se nao for a primeira palavra
            int num_caracteres = i == 0 ? palavra.size() : palavra.size() + 1;  
            
            if (contador_caracteres - num_caracteres >= 0) contador_caracteres -= num_caracteres;

            // Palavra deve ser escrita na próxima linha
            else {
                contador_linhas++;

                // Eh inicio de linha 
                // Desconsiderar espaço antes da palavra 
                num_caracteres--;

                contador_caracteres = C - num_caracteres;

                // Preencheu uma página
                if (contador_linhas > L) {
                    contador_linhas = 1;
                    num_minimo_paginas++;
                }
            }
        }

        cout << num_minimo_paginas << endl;
    }
    
    
}