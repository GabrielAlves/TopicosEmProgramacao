#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> maiores_notas(5, -1);
    vector<int> notas(5);
    int happy = 0, happier = 0, happiest = 0;

    for (int i = 0; i < n; i++) {
        cin >> notas[0] >> notas[1] >> notas[2] >> notas[3] >> notas[4];

        int notas_altas = 0;
        for (int j = 0; j < 5; j++) {
            if (notas[j] > maiores_notas[j]) {
                notas_altas++;
                maiores_notas[j] = notas[j];
            }
        }

        if (notas_altas == 3) happy++;
        else if (notas_altas == 4) happier++;
        else if (notas_altas == 5) happiest++;
    }

    cout << happy << " " << happier << " " << happiest << endl;
}