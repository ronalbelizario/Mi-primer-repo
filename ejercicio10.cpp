#include <iostream>
using namespace std;

int main() {
    int A = 7;
    int B = 3;
    int C = ++A + B--;
    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "C=" << C << endl;
    return 0;
}