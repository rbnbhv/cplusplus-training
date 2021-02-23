/*
 20.03.2020 - Ruben Allenstein
 Aufgabe 3:
 Programmieren Sie eine Methode, die zwei int Zahlen i1 und i2 übergeben bekommt und diejenige Zahl zurückliefert,
 die mehr Einsen in ihrer Binärdarstellung enthält. (Bitshifting)
 Hinweis: Zerlegen Sie Ihre Lösungen immer in sinnvolle Hilfsmethoden.
 */

#include <iostream>
using namespace std;

int checkZahl(int n) {
    int cnt = 0;
    for (int i = 0; i < 32; ++i) {
        if ((n &(1 << i)) != 0) {
            ++cnt;
        }
    }
    return cnt;
}

int binaerStellen(int n, int m) {
    if (checkZahl(n) >= checkZahl(m)) {
        return n;
    }
    else {
        return m;
    }
    return 0;
}

int main() {
    int n = 1, m = 2;
    cout << binaerStellen(n,m) << endl;
}
