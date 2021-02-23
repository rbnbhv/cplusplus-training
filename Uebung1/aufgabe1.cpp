/* 20.03.2020 - Ruben Allenstein
 Programmieren Sie eine Methode, die folgendes auf dem Bildschirm ausgibt:
   *
  ***
 *****
  ***
   *
 Dabei soll die Höhe durch einen Parameter zeilenMax angegeben werden.
 */

#include <iostream>
using namespace std;

void raute(int zeilenMax) {
    for (int zeilen = 0; zeilen < (zeilenMax / 2) + (zeilenMax % 2 == 0 ? 0 : 1); ++zeilen) {
        for (int spalten = 0; spalten <= zeilenMax - zeilen - 1; ++spalten) {
            cout << " ";
        }
        for (int k = 0; k < zeilen * 2 + 1; ++k) {
            cout << "X";
        }
        cout << endl;
    }
    
    for (int zeilenUnten = zeilenMax/2-1; zeilenUnten >= 0; --zeilenUnten) {
        for (int spaltenUnten = 0; spaltenUnten < zeilenMax-zeilenUnten; ++spaltenUnten) {
            cout << " ";
        }
        for (int k = 0; k < zeilenUnten * 2 + 1; ++k) {
            cout << "X";
        }
        cout << endl;
    }
}

int main() {
    int zeilenMax = 5;
    raute(zeilenMax);
}
