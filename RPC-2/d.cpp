#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num_cartas, carta;
    cin >> num_cartas;

    vector<int> cartas_alice(num_cartas);

    for (int i = 0; i < num_cartas; i++) {
        cin >> carta;
        cartas_alice[i] = carta;
    }

    sort(cartas_alice.begin(), cartas_alice.end());

    vector<int> cartas_bob(num_cartas);
    int j = 0;
    int i = 0;

    for (int n = 1; n <= num_cartas * 2; n++) {
        if (n == cartas_alice[j]) {
            j++;
        }

        else {
            cartas_bob[i] = n;
            i++;
        }
        
    }
    vector<int> aux_alice = cartas_alice;
    vector<int> aux_bob = cartas_bob;

    int maximo_pontos = 0, minimo_pontos = num_cartas;

    for (int i = 0; i < num_cartas; i++) {
        auto it_min = upper_bound(aux_bob.begin(), aux_bob.end(), cartas_alice[i]);
        auto it_max = upper_bound(aux_alice.begin(), aux_alice.end(), cartas_bob[i]);

        if (it_min != aux_bob.end()) {
            minimo_pontos--;
            aux_bob.erase(it_min);
        }

        if (it_max != aux_alice.end()) {
            maximo_pontos++;
            aux_alice.erase(it_max);
        }
    }

    cout << minimo_pontos << " " << maximo_pontos << endl;
}