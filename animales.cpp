#include <iostream>
#include <string>
using namespace std;
int main() {
    string t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    if (t1 == "vertebrado") {
        if (t2 == "ave") {
            if (t3 == "carnivoro") {
                cout << "aguia\n";
            } else {
                cout << "pomba\n";
            }
        } else {
            if (t3 == "onivoro") {
                cout << "homem\n";
            } else {
                cout << "vaca\n";
            }
        }
    }
    else {
        if (t2 == "inseto") {
            if (t3 == "hematofago") {
                cout << "pulga\n";
            } else {
                cout << "lagarta\n";
            }
        } else {
            if (t3 == "hematofago") {
                cout << "sanguessuga\n";
            } else {
                cout << "minhoca\n";
            }
        }
    }
    return 0;
}