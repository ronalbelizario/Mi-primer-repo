#include <iostream>
using namespace std;

int main() {
    int A,B;
    cin >> A >> B;

    if (A > B) {
        cout << "El negocio si va jalar\n";
        cout << (A- B) << "\n";
    } else {
        cout << "Dejalo ya esta muerto\n";
        cout << (B - A) << "\n";
    }

    return 0;
}