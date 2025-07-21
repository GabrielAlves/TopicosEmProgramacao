#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, C;

    int caso = 1;
    while (cin >> N && cin >> C && N && C) {
        vector<int> pesos(N);
        vector<int> interesses(N);

        for (int i = 0; i < N; i++) {
            cin >> pesos[i] >> interesses[i];
        }

        vector<int> somas(C + 1, -1);
        somas[0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = C; j >= 0; j--) {
                if (somas[j] != -1 && j + pesos[i] <= C) somas[j + pesos[i]] = max(somas[j + pesos[i]], somas[j] + interesses[i]);
            }
        }

        int maior = -INT_MAX;
        for (int i = 0; i <= C; i++) {
            if (somas[i] != -1 && somas[i] > maior) maior = somas[i];
        }

        cout << "Caso " << caso++ << ": " << maior << endl;
    }
    
}