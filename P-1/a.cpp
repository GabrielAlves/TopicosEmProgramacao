#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_candidatos, num_apartamentos, k, resultado = 0;
    cin >> num_candidatos >> num_apartamentos >> k;

    vector<int> desejados(num_candidatos);
    vector<int> apartamentos(num_apartamentos);

    for (int i = 0; i < num_candidatos; i++) {
        cin >> desejados[i];
    }

    sort(desejados.begin(), desejados.end());
    for (int i = 0; i < num_apartamentos; i++) {
        cin >> apartamentos[i];
    }

    sort(apartamentos.begin(), apartamentos.end());

    int i = 0, j = 0;
    while (i < num_candidatos && j < num_apartamentos) {
        if ((apartamentos[j] >= desejados[i] - k) && (apartamentos[j] <= desejados[i] + k)) {
            resultado++;
            j++;
            i++;
        }

        if (apartamentos[j] < desejados[i] + k) j++;

        if (apartamentos[j] > desejados[i] - k) i++;
    }

    cout << resultado << endl;
}