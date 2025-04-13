#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int datas_quadradas = 0;

    for (int i = 45; i < 100; i++) {
        double ano_quadrado = pow(i, 2);

        if (ano_quadrado > b) {
            break;
        }

        if (ano_quadrado >= a) {
            datas_quadradas += 15;
        }

    }

    cout << datas_quadradas << endl;
    }