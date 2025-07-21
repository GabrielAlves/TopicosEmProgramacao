#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int V, M;
    cin >> V >> M;
    vector<int> moedas(M);
    
    for (int i = 0; i < M; i++) {
        cin >> moedas[i];
    }

    vector<bool> possivel(V + 1, false);
    possivel[0] = true;
    
    for (int i = 0; i < M; i++) {
        for (int j = V; j >= 0; j--) {
            if (possivel[j] && j + moedas[i] <= V) possivel[j + moedas[i]] = true;
        }
    }

    cout << (possivel[V] ? "S" : "N") << endl;
}