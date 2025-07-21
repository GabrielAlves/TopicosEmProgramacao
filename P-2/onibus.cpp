#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> arvore, vector<int> &distancias, int a, int p) {
    distancias[a] = distancias[p] + 1;

    for (int u : arvore[a]) {
        if (u != p) dfs(arvore, distancias, u, a);
    }
}

int main() {
    int N, A, B, P, Q;
    cin >> N >> A >> B;

    vector<vector<int>> arvore(N+1);

    for (int i = 0; i < N - 1; i++) {
        cin >> P >> Q;
        arvore[P].push_back(Q);
        arvore[Q].push_back(P);
    }

    vector<int> distancias(N + 1);
    distancias[0] = -1;
    dfs(arvore, distancias, A, 0);

    cout << distancias[B] << endl;
}