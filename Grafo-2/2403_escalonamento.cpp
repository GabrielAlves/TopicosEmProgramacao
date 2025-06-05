#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, A, B;
    cin >> N >> M;

    vector<vector<int>> precede(N);
    vector<int> graus_entrada(N, 0);
    vector<int> ordem;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graus_entrada[B]++;
        precede[A].push_back(B);
    }

    priority_queue<int> fila;
    for (int i = 0; i < N; i++) {
        if (graus_entrada[i] == 0) {
            fila.push(-i);
        }
    }
    while (!fila.empty()) {
        int u = -fila.top();
        fila.pop();
        ordem.push_back(u);

        for (auto v : precede[u]) {
            graus_entrada[v]--;
            if (graus_entrada[v] == 0) fila.push(-v);
        }
    }

    if (ordem.size() == N) {
        for (int u : ordem) {
            cout << u << endl;
        }
    }

    else {
        cout << "*" << endl;
    }
}