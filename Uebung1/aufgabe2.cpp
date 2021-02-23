/* 20.03.2020 - Ruben Allenstein
 Aufgabe 2:
 Programmieren Sie eine Methode, die eine Zahl n übergeben bekommt und alle
 Primzahlen < n auf dem Bildschirm ausgibt.
 */

#include <iostream>
using namespace std;

bool checkZahl(int n) {
    for (int i = 2; i < n; ++i) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

void isPrim(int n) {
    for (int i = 1; i < n; ++i) {
        if (checkZahl(i)) {
            cout << i << endl;
        }
    }
}

int main() {
    int n = 100;
    isPrim(n);
    return 0;
}
