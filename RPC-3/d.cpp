#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string texto, remocoes, mensagem = "";
    getline(cin, texto);
    getline(cin, remocoes);
    map<char, int> foi_removido;

    for (char caracter : remocoes) {
        if (caracter == '[' || caracter == ']') continue;
        foi_removido[caracter] = 1;
    }

    char ultimo_caracter = '_';
    for (char caracter : texto) {
        if (foi_removido[caracter]) continue;
        if (caracter == ' ' && mensagem == "") continue;

        if (caracter != ultimo_caracter) {
            mensagem += caracter;
            ultimo_caracter = caracter;
        }
    }

    while (mensagem[mensagem.size() - 1] == ' ') mensagem.erase(mensagem.size() - 1, 1);
    cout << mensagem << endl;
}