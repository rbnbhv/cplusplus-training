/*
 07.04.2020 - Ruben Allenstein
 Aufgabe 3:
 Schreiben Sie die Funktion rev, die einen String (char-Pointer) übergeben bekommt und einen neuen String (char-Pointer)
 zurückliefert, der das gespiegelte Wort enthält. Vermeiden Sie vordefinierten Funktionen wie strlen, cpy.
 */

#include <iostream>
using namespace std;

//Prototypen der Funktionen:
int stringLaenge(char* wort);
char* rev(char* wort);

//Länge ÜBER den Pointer ermitteln!:
unsigned getLength(char* wort) {
    unsigned i = 0;                   // auch schreibbar: int laenge{0}
    while (wort[i] != '\0') {
        ++i;
    }
    return i;
}

char* rev(char* wort) {
    char* tmp;
    unsigned length = getLength(wort);
    for (int i = 0; i < length/2; ++i) {
        char tmp = wort[i];
        wort[i] = wort[length-i-1];
        wort[length-i-1] = tmp;
    }
    return tmp;
}

int main() {
    char str[] = "In einem Land!";
    cout << str << endl;
    rev(str);
    cout << str << endl;
    return 0;
}
