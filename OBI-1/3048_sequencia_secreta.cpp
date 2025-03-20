#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, V, ultimo_sequencia = -1, tam_max = 0;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> V;

        if (V != ultimo_sequencia) {
            tam_max++;
            ultimo_sequencia = V;
        }
    }
    cout << tam_max << endl;

}