#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, preco;

    cin >> n >> m;

    vector<int> ingressos(n);

    for (int i = 0; i < n; i++) {
        cin >> ingressos[i];
    }

    sort(ingressos.begin(), ingressos.end());

    for (int i = 0; i < m; i++) {
        cin >> preco;

        auto it_lower = lower_bound(ingressos.begin(), ingressos.end(), preco);
    
        if (it_lower != ingressos.end() && *it_lower == preco) {
            cout << (*it_lower) << endl;
            ingressos.erase(it_lower);
        }

        else if (it_lower != ingressos.end() && it_lower != ingressos.begin() && *it_lower > preco) {
            cout << (*(it_lower - 1)) << endl;
            ingressos.erase(it_lower - 1);
        }

        else {
            cout << -1 << endl;
        }
    }
}