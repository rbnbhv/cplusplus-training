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
    int erg = 0;
    for (int i = 0; i <= b-1; ++i) {
        erg += a;
    }
    return erg;
}

int main() {
    cout << mult_iter(10, 5) << endl;
}
