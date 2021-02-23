/*
 SS2020 Teil1 - Aufgabe 3:
 Implementieren Sie eine C++ Funktion char* replace(const char* src, char c, const char* text), die jedes
 Vorkommen des Buchstabens c in dem übergebenen char Array src durch das char Array text ersetzt und das
 Ergebnis zurück gibt. Beispiel: replace("hello World", 'l', "JUHU") ergibt "heJUHUJUHUo worJUHUd". Sie
 dürfen keine vordefinierten Methoden, Funktionen oder Klassen verwenden. Bilden Sie sinnvolle Hilfsfunktionen.
 
 --> Meine Aufgabe:
 1: char *replace
 2: getLength Methode (Laenge für neues Array bestimmen)
 */

#include <iostream>
using namespace std;

unsigned getLength(const char *text) {
    unsigned i = 0;
    while (text[i] != '\0') {
        ++i;
    }
    return i;
}

char *replace(const char *src, char c, const char *text) {
    // 1. Phase:
    unsigned i = 0, counter = 0, k = 0;
    while (src[i] != '\0') {
        if (src[i] == c) {
            ++counter;
        }
        ++i;
    }
    
    int newLength = getLength(src) - counter + getLength(text) * counter + 1;
    i = 0;
    char *newText = new char[newLength];
    while (src[i] != '\0') {
        if (src[i] == c) {
            unsigned j = 0;
            while (text[j] != '\0') {
                newText[k++] = text[j++];
            }
        }
        else {
            newText[k++] = src[i];
        }
        ++i;
    }
    newText[k] = '\0';
    return newText;
}

int main() {
    cout << replace("hello World", 'l', "JUHU") << endl;
}
