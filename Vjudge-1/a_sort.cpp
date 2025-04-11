#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, V;

    cin >> N;
    vector<int> numeros(N);

    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    sort(numeros.begin(), numeros.end());

    for (auto v : numeros) {
        cout << v << " ";
    }

}