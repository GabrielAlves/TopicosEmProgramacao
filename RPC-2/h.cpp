#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ervas_verdes, ervas_vermelhas, aumento_saude = 0;

    cin >> ervas_verdes >> ervas_vermelhas;

    if (ervas_vermelhas >= 1 && ervas_verdes >= 1) {
        int quant = min(ervas_verdes, ervas_vermelhas);
        aumento_saude += quant * 10;
        ervas_verdes -= quant;
    }

    if (ervas_verdes > 2) {
        aumento_saude += (ervas_verdes / 3) * 10;
        ervas_verdes = ervas_verdes % 3;
    }

    if (ervas_verdes > 1) {
        aumento_saude += (ervas_verdes / 2) * 3;
        ervas_verdes = ervas_verdes % 2;
    }

    if (ervas_verdes > 0) {
        aumento_saude++;
    }

    cout << aumento_saude << endl;
}