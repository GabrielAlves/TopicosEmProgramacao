#include <bits/stdc++.h>

using namespace std;

int main() {
    string expressao;
    cin >> expressao;
    stack<char> pilha;
    map<char, char> inverso {{')', '('}, {']', '['}, {'}', '{'}};

    int eh_equilibrada = 1;
    for (char caracter : expressao) {
        if (caracter == '(' || caracter == '[' || caracter == '{') pilha.push(caracter);
        else {
            if (!pilha.empty() && pilha.top() == inverso[caracter]) pilha.pop();
            else {
                eh_equilibrada = 0; break;
            }
        }
    }

    if (!pilha.empty()) eh_equilibrada = 0;

    cout << eh_equilibrada << endl;
}