#include<bits/stdc++.h>

using namespace std;

int main() {
    int B, T;
    double area1, area2;
    cin >> B >> T;

    area1 = ((B + T) * 70) / 2; // area do trapezio da esquerda
    area2 = abs(11200 - area1); // area total menos a area1

    if (area1 > area2) {
        cout << 1 << endl; // felix venceu
    }

    else if (area1 < area2) {
        cout << 2 << endl; // marzia venceu
    }

    else {
        cout << 0 << endl;
    }
}