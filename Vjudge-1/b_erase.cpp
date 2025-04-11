#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, V;

    cin >> N;
    vector<int> numeros(N);

    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    int x, a, b;

    cin >> x;

    numeros.erase(numeros.begin() + (x - 1));

    cin >> a >> b;

    numeros.erase(numeros.begin() + (a - 1), numeros.begin() + (b - 1));

    cout << numeros.size() << endl;
    for (auto v : numeros) {
        cout << v << " ";
    }

}