#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, quantum, timestamp = 0, tempo_processo;
    string nome;
    cin >> n >> quantum;
    queue<pair<string, int>> fila;
    
    for (int i = 0; i < n; i++) {
        cin >> nome >> tempo_processo;
        fila.emplace(nome, tempo_processo);
    }

    while (!fila.empty()) {
        pair<string, int> processo = fila.front();
        tempo_processo = processo.second - quantum; 
        timestamp += processo.second >= quantum ? quantum : processo.second;

        if (tempo_processo <= 0) {
            cout << (processo.first) << " " << timestamp << endl;
        }

        else{
            fila.push({processo.first, tempo_processo});
        }

        fila.pop();
    }
}