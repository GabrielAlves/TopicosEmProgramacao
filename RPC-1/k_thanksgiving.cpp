#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, pessoa;
    cin >> n;

    vector<bool> visitados(n + 1, false);
    vector<int> grafo(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> pessoa;

        grafo[i] = pessoa;
    }

    queue<int> fila;
    fila.push(1);
    int pessoas_na_fofoca = 1;
    visitados[1] = true;

    while (!fila.empty()) {
        int pessoa = fila.front();
        int ouvinte = grafo[pessoa];
        fila.pop();

        if (!visitados[ouvinte]) {
            pessoas_na_fofoca++;
            fila.push(ouvinte);
            visitados[ouvinte] = true;
        }
    }

    cout << pessoas_na_fofoca << endl;

    }