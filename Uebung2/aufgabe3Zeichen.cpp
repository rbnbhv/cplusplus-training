/*
 27.03.2020 - Ruben Allenstein
 Aufgabe 3:
 Schreiben Sie eine Methode, die solange Zeichen von der Tastatur einliest, bis ein Zeichen ungleich der Ziffern eingegeben
 wird. Das erste Zeichen darf aber auch das ‚–‘ Minus sein. Die Methode soll die Zahl errechnen, die aus der Reihenfolge der
 Ziffern besteht. Beispieleingabe: - 2 3 4 2 5, Ausgabe: die Zahl –23425.
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


string create() {
    string s;
    char c;
    cout << "Bitte Zahl eingeben: " << endl;
    while (cin >> c) {
        if (s == "" && (int)c == 45) {
            s += c;
        }
        else if ((int)c > 47 && (int)c < 58) {
            s += c;
        }
        else{
            return s;
        }
    }
    return s;
}

int convert() {
    string s = create();
    int i = 0;
    istringstream(s) >> i;
    
    return i;
}

int main() {
    int i = convert();
    cout << i << endl;
    return 0;
}
