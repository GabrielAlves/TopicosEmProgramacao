#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, preco;
    cin >> n >> m;
    vector<int> bilhetes(n);

    for (int i = 0; i < n; i++) cin >> bilhetes[i];
    sort(bilhetes.begin(), bilhetes.end());

    for (int i = 0; i < m; i++) {
        cin >> preco;

        auto lb = lower_bound(bilhetes.begin(), bilhetes.end(), preco);

        if (lb != bilhetes.end() && *lb == preco) {
            cout << *lb << endl;
            bilhetes.erase(lb); 
        }

        else if (lb != bilhetes.end() && lb != bilhetes.begin() && *(lb - 1) < preco) {
            cout << *(lb - 1) << endl;
            bilhetes.erase(lb - 1);
        }

        else {
            cout << -1 << endl;
        }
    }
}