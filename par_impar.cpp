#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingresa un numero: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Par" << endl;
    }
    else {
        cout << "Impar" << endl;
    }

    return 0;
}