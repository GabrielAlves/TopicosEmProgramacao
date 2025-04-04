#include <bits/stdc++.h>

using namespace std;

int main() {
    int q, num;
    string comando;

    cin >> q;
    deque<int> dq;
    bool invertido = false;
    for (int i = 0; i < q; i++) {
        cin >> comando;

        if (comando == "back" || comando == "front") {
            if (dq.empty()) {
                cout << "No job for Ada?" << endl;
            } 

            else {
                if (comando == "back" && invertido) {
                    cout << dq.front() << endl;
                    dq.pop_front();
                }

                else if (comando == "back") {
                    cout << dq.back() << endl;
                    dq.pop_back();
                }

                else if (comando == "front" && invertido) {
                    cout << dq.back() << endl;
                    dq.pop_back();
                }

                else if (comando == "front") {
                    cout << dq.front() << endl;
                    dq.pop_front();
                }
            }
        }

        else if (comando == "reverse") {
            invertido = invertido == false;
        }

        else if (comando == "push_back" || comando == "toFront") {
            cin >> num;

            if (comando == "push_back" && invertido) {
                dq.push_front(num);
            }

            else if (comando == "push_back") {
                dq.push_back(num);
            }

            else if (comando == "toFront" && invertido) {
                dq.push_back(num);                
            }

            else if (comando == "toFront") {
                dq.push_front(num);
            }
        }
    }

}