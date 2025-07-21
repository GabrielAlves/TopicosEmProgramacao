#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        vector<int> numeros(N);

        for (int j = 0; j < N; j++) {
            cin >> numeros[j];
        }

        sort(numeros.begin(), numeros.end());

        long long menor = 1;
        for (int n : numeros) {
            if (menor >= n) menor += n;
            else break;
        }

        cout << menor << endl;
    }
    
}