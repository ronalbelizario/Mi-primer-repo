#include <iostream>
using namespace std;

int main() {
    int A = 7;
    int B = 3;
    int C = A * 2 + B % 2;
    A = A + B * 3 - C/2;
    B = C % 3 + A/2;
    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "C=" << C << endl;
    return 0;
}