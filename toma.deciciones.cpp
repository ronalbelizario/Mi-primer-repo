#include <iostream>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    if (A + B ==5) {
        B += 3;
        cout << 2*A + B << endl;
    } else {
        A -= 1;
        int valor = 7*A + B;

        if (valor % 2 == 0) {
            cout << A - B << endl;
        } else {
            cout << A * B << endl;
        }
    }
    return 0;
}