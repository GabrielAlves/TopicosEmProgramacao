#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, inicio, fim;
    cin >> N;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < N; i++) {
        cin >> inicio >> fim;
        pq.push({-fim, inicio});
    }
    
    int num_consultas = 0, ultimo_fim = -1;
    while (!pq.empty()) {
        pair<int, int> horario = pq.top();
        pq.pop();

        inicio = horario.second;
        fim = -horario.first;

        if (inicio >= ultimo_fim) {
            ultimo_fim = fim;
            num_consultas++;
        }
    }

    cout << num_consultas << endl;
}