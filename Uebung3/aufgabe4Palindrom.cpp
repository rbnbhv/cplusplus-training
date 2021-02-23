/*
07.04.2020 - Ruben Allenstein
 Aufgabe 4:
 Schreiben Sie die Funktion pal, die einen String (char-Pointer) übergeben bekommt und einen booleschen Wert zurückliefert.
 Der Wert ist true, genau dann wenn das übergebene Wort ein Palindrom ist. Vermeiden Sie vordefinierten Funktionen wie
 strlen, cpy.
 */

#include <iostream>
using namespace std;

bool pal(char *p) {
    // cout << *p << p[1] << p[2] << endl;
    int cnt = 0;
    for (int i = 0; p[i] != '\0'; ++i) {
        ++cnt;
    }
    for (int i = 0; i <= cnt; ++i) {
        if (p[i] != p[cnt-1-i]) {
            return false;
        }
    }
    return true;
 }

bool pal(string p) {
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] != p[p.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void testPalinPointer(char *p) {
    if (pal(p)) {
        cout << "Das Wort " << p << " ist ein Palindrom!" << endl;
    }
    else {
        cout << "Das Wort " << p << " ist kein Palindrom!" << endl;
    }
}


void testPalin(string s) {
    if (pal(s)) {
        cout << "Das Wort " << s << " ist ein Palindrom!" << endl;
    }
    else {
        cout << "Das Wort " << s << " ist kein Palindrom!" << endl;
    }
}

int main() {
    string s = "otto";
    char* c = "otto";
    testPalinPointer(c);
    testPalin(s);
    
    cout << "Die Länge des Strings ist " << s.length() << endl;
    cout << "True oder False werden ausgegeben als " << pal(s) << endl;
    return 0;
}
