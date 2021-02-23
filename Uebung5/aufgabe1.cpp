/*
 15.06.2020 - Ruben Allenstein
 Aufgabe 1:
 Implementieren Sie eine Klasse Rational zur Speicherung und Darstellung rationaler Zahlen.
 Implementieren Sie sinnvolle Konstruktoren und Operatoren (+, -, *, /, <, <=, >, >=, ==, !=, <<, =).
 Die Speicherung soll immer in gekürzter Form erfolgen.
 */

#include <iostream>

using namespace std;

class Rational {
private:
    unsigned zaehler;
    unsigned nenner;
    
public:
    Rational() {}
    Rational(unsigned int z, unsigned int n) {
        zaehler = z;
        nenner = n;
    };
    
    ~Rational() {
        cout << "Destuktor wird aufgerufen" << endl;
    }
    
    void set_zaehler(unsigned zaehler) {
        this->zaehler = zaehler;
    }
    
    void set_nenner(unsigned nenner) {
        this->nenner = nenner;
    }
    
    int get_zaehler() {
        return zaehler;
    }
    
    int get_nenner() {
        return nenner;
    }
    
    // den prototyp der funktionen als friend deklarieren
    // damit kann die funktion auf alles was privat ist zugreifen
    friend Rational operator+(const Rational&,const Rational&);
    // den << operator ueberladen
    friend ostream& operator<<(ostream&,const Rational&);
};
// den + operator ueberladen
Rational operator+(const Rational& crArg1,const Rational& crArg2) {
    // die funktion liefert ein objekt der klasse rational zurueck
    // da sie die funktion kuerzen noch nicht implementiert haben wird der ungekuerzte bruch zurueckgegeben
    return Rational (crArg1.zaehler * crArg2.nenner +crArg2.zaehler * crArg1.nenner, crArg1.nenner * crArg2.nenner);
}

// den ausgabe operator ueberladen
ostream& operator<<(ostream& os,const Rational& crArg) {
    os  << crArg.zaehler << "/" << crArg.nenner<<endl;
    return os;
}

int main() {
    Rational *r1 = new Rational(4,8);
    Rational *r2 = new Rational(2,8);
    // das es sich um objekte auf dem heap handelt
    // muss der pointer bei der ausgabe wieder dereferenziert werden
    cout<<*r1 + *r2;
    // die beiden objekte liegen im stack
    // deswegen braucht hier auch nicht dereferenziert werden
    Rational r4(5,7);
    Rational r5(3,4);
    cout<<r4 + r5;
    return 0;
}
