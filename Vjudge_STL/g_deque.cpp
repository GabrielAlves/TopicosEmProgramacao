#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, k;
    
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;

        deque<int> dq(k);
        vector<int> numeros(n);

        for (int j = 0; j < n; j++) {
            cin >> numeros[j];
        }

        for (int j = 0; j < k; j++) {
            while (!dq.empty() && numeros[j] >= numeros[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        for (int j = k; j < numeros.size(); j++) {
            cout << numeros[dq.front()] << " ";

            while (!dq.empty() && dq.front() <= j - k) {
                dq.pop_front();
            }

            while (!dq.empty() && numeros[j] >= numeros[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        cout << numeros[dq.front()] << endl;
    }

}