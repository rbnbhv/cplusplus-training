#include <iostream>

using namespace std;

int main() {
    int x = 15;
    int p = 27;
    int *px = &x;
    cout << "mit *variablenname wird der Wert der Variable auf dem Speicherplatz, auf dem der Pointer zeigt, angezeigt" << endl;
    cout << "*px gibt den Wert: " << *px << endl;
    cout << "px gibt den Wert: "<< px << endl;
    
    cout << endl << endl;
    cout << "Die Speicheradresse kann wie folgt geändert werden!" << endl;
    px = &p;
    cout << *px << endl;
    
}
