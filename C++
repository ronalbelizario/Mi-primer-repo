#include <iostream>
using namespace std;
int main() {
    int A = 12, B = 4;
    int C = A/B + A % B * 2;
    cout << "C=" << C << endl;
    return 0;
}