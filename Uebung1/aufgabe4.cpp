/*
 20.03.2020 - Ruben Allenstein
 Aufgabe 4:
 Zwei Zahlen a und b können dadurch multipliziert werden, dass eine Schleife von 0 bis b-1 läuft und immer wieder zum
 Ergebnis a hinzuaddiert. Implementieren Sie eine Methode mult_iter, die dieses Verfahren iterativ implementiert und eine
 Methode mult_rec, die dieses Verfahren rekursiv implementiert. Beachten Sie, dass a und b auch jeweils negativ sein können.
 */

#include <iostream>
using namespace std;

int mult_iter(int a, int b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    int erg = 0;
    for (unsigned i = 0; i <= b-1; ++i) {
        erg += a;
    }
    return erg;
}

int mult_rek(int a, int b, int erg, int i) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (i < b-1) {
        return mult_rek(a,b, erg + a, ++i);
    }
    return erg;
}

















int mult_iter(int a, int b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    int erg = 0;
    for (int i = 0; i <= b-1; ++i) {
        erg += a;
//        cout << erg << endl;
    }
    return erg;
}

int mult_rek(int a, int b, int i, int erg) {
    if (i <= b-1) {
        erg += a;
//        cout << erg << endl;
        return mult_rek(a, b, i+1, erg);
    }
    return a;
}

int mult_rek(int a, int b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    return mult_rek(a, b, 0, 0);
}

int main() {
    int a = -5, b = +8;
    mult_iter(a, b);
    cout << endl << endl;
    mult_rek(a, b);
    cout << endl << endl;
}
