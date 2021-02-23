/*
 07.04.2020 - Ruben Allenstein
 Aufgabe 2:
 Schreiben Sie die Funktion cat, die zwei Strings (char-Pointer) übergeben bekommt und einen neuen String (char Pointer)
 zurückliefert, der die Konkatenation der beiden enthält. Vermeiden Sie vordefinierten Funktionen wie strlen, cpy..
 */

#include <iostream>
using namespace std;

// Prototypen der Funktionen:
char* cat(char* stringOne, char* stringTwo);
unsigned getLength(char wort[]);

int main(){
    char stringEins[] = "In einem Land ";
    char stringZwei[] = "vor unserer Zeit";
    char* newString = cat(stringEins, stringZwei);
    cout << newString << endl;
    return 0;
}

char* cat(char* stringOne, char* stringTwo) {
    unsigned int lengthOne = getLength(stringOne);
    unsigned int lengthTwo = getLength(stringTwo);
    unsigned int newLength = lengthOne + lengthTwo;
    char* newString = new char[newLength];
    unsigned j = 0;
    for (unsigned i = 0; i < newLength; ++i) {
        while (i < lengthOne) {
            newString[i] = stringOne[i];
            ++i;
        }
        while (j < lengthTwo) {
            newString[i] = stringTwo[j];
            ++j;
            ++i;
        }
    }
    return newString;
}

// Liefert die Länge des Char Arrays zurück!
unsigned getLength(char* wort) {
    unsigned i = 0;
    while (wort[i] != '\0') {
        ++i;
    }
    return i;
}
