#include <iostream>
using namespace std;

int main() {
    int X = 5;
    int Y = ++X * X--;
    cout << "X=" << X << endl;
    cout << "Y=" << Y << endl;
    return 0;
}