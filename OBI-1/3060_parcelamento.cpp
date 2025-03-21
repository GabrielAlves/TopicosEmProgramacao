#include <bits/stdc++.h>

using namespace std;

int main() {
    int V, P;
    cin >> V >> P;
    int resto = V % P;
    
    for (int i = 0; i < P; i++) {
        if (resto == 0) {
            cout << (V / P) << endl;
        }

        else {
            cout << (V / P) + 1 << endl;
            resto--;
        }

    }
}