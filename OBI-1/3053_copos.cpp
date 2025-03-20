#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, operacao;
    char copo_com_moeda;
    cin >> N >> copo_com_moeda;

    for (int i = 0; i < N; i++) {
        cin >> operacao;

        if (operacao == 1) {
            if (copo_com_moeda == 'A') {
                copo_com_moeda = 'B';
            }

            else if (copo_com_moeda == 'B') {
                copo_com_moeda = 'A';
            }
        }

        else if (operacao == 2) {
            if (copo_com_moeda == 'B') {
                copo_com_moeda = 'C';
            }

            else if (copo_com_moeda == 'C') {
                copo_com_moeda = 'B';
            }
        }

        else {
            if (copo_com_moeda == 'A') {
                copo_com_moeda = 'C';
            }

            else if (copo_com_moeda == 'C') {
                copo_com_moeda = 'A';
            }
        }
    }
    cout << copo_com_moeda << endl;

    }