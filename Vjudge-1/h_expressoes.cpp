#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string expressao;
    cin >> n;
    
    map<char, char> inverso;
    inverso[')'] = '(';
    inverso[']'] = '[';
    inverso['}'] = '{'; 

    for (int i = 0; i < n; i++) {
        cin >> expressao;

        stack<char> pilha;
        bool balanceado = true;
        for (char caracter : expressao) {
            if (caracter == '(' || caracter == '[' || caracter == '{') {
                pilha.push(caracter);
            }

            else {
                if (!pilha.empty() && pilha.top() == inverso[caracter]) {
                    pilha.pop();
            
                }

                else{
                    balanceado = false;
                    break;
                }
            }
        }

        if (!pilha.empty()) {
            balanceado = false;
        }

        if (balanceado) {
            cout << "YES" << endl;
        }

        else {
            cout << "NO" << endl;
        }
    }

}