/*
 07.07.2020 - Ruben Allenstein
 Aufgabe 1:
 Implementieren Sie eine Klasse Rational zur Speicherung und Darstellung rationaler Zahlen.
 Implementieren Sie sinnvolle Konstruktoren und Operatoren (+, -, *, /, <, <=, >, >=, ==, !=, <<, =).
 Die Speicherung soll immer in gekürzter Form erfolgen.
 */

#include <iostream>

using namespace std;

class Rational {
private:
    int zaehler;
    int nenner;
    Rational *tmp;
    
public:
    Rational() {
        zaehler = 0;
        nenner = 1;
    }
    
    // Nur Initialisierung, Keine Ausgabe
    Rational(int z, int n) {
        zaehler = z;
        nenner = n;
    }
    
    Rational operator+(const Rational &r) {
        int z = zaehler * r.nenner + nenner * r.zaehler;
        int n = nenner * r.nenner;
        // ggTrek(z, n);
        Rational rNew((z / ggTrek(z,n)),(n / ggTrek(z,n)));
        //ggTrek
        return rNew;
    }
    
    Rational operator-(const Rational &r) {
        int z = zaehler * r.nenner - nenner * r.zaehler;
        int n = nenner * r.nenner;
        Rational rNew((z / ggTrek(z,n)), (n / ggTrek(z,n)));
        return rNew;
    }
    
    Rational operator*(const Rational &r) {
        int z = zaehler * r.zaehler;
        int n = nenner * r.nenner;
        Rational rNew((z / ggTrek(z,n)), (n / ggTrek(z,n)));
        return rNew;
    }
    
    Rational operator/(const Rational &r) {
        int z = zaehler * r.nenner;
        int n = nenner * r.zaehler;
        Rational rNew((z / ggTrek(z, n)) , (n / ggTrek(z, n)));
        return rNew;
    }
    
//    Rational& operator=(const Rational &r) {
//        if (this != &r) {
//            return *this;
//        }
//        cout << "copy assignment: ";
//        zaehler = r.zaehler / ggTrek(zaehler, nenner);
//        nenner = r.nenner / ggTrek(zaehler, nenner);
//        return *this;
//    }
    
    bool operator<(Rational &r) {
        if(nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        if(r.nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        
        int zahl1 = zaehler * r.nenner;
        int zahl2 = r.zaehler * nenner;
        if (zahl1 < zahl2) {
            return true;
        }
        return false;
    }
    
    bool operator>(Rational &r) {
        if(nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        if(r.nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        
        int zahl1 = zaehler * r.nenner;
        int zahl2 = r.zaehler * nenner;
        if (zahl1 > zahl2) {
            return true;
        }
        return false;
    }
    
    bool operator<=(Rational &r) {
        if(nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        if(r.nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        
        int zahl1 = zaehler * r.nenner;
        int zahl2 = r.zaehler * nenner;
        if (zahl1 <= zahl2) {
            return true;
        }
        return false;
    }
    
    bool operator>=(Rational &r) {
        if(nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        if(r.nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        
        int zahl1 = zaehler * r.nenner;
        int zahl2 = r.zaehler * nenner;
        if (zahl1 >= zahl2) {
            return true;
        }
        return false;
    }
    
    bool operator==(Rational &r) {
        if(nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        if(r.nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        
        int zahl1 = zaehler * r.nenner;
        int zahl2 = r.zaehler * nenner;
        if (zahl1 == zahl2) {
            return true;
        }
        return false;
    }
    
    bool operator!=(Rational &r) {
        if(nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        if(r.nenner > 0) {
            nenner = -nenner;
            r.nenner = -r.nenner;
        }
        
        int zahl1 = zaehler * r.nenner;
        int zahl2 = r.zaehler * nenner;
        if (zahl1 != zahl2) {
            return true;
        }
        return false;
    }
    
    
    int ggTrek(int z, int n) {
//          ist das gleiche wie Zeile 187!
//        if(n == 0) {
//            return z;
//        }
//            return ggTrek(n, z % n);
//        }
     return n==0 ? z : ggTrek(n, z % n);  // gelesen: wenn n == 0, dann return z, sonst return ggTrek(n, z%n)
    }

    // Wichtig: Hier muss ein friend davor, um auf die privaten Elemente Zugriff zu haben!
    friend ostream& operator<<(ostream& os, Rational &r) {
        if (r.nenner == 1) {
            os << r.zaehler << endl;
        }
        else if(r.nenner < 0) {
            r.nenner = -r.nenner;
            r.zaehler = r.zaehler;
            os << r.zaehler << " / " << r.nenner;
        }
        else {
            os << r.zaehler << " / " << r.nenner;
        }
    return os;
    }
    
//    ~Rational() {
//        cout << "Destruktor wird11 aufgerufen!" << endl;
//    }
};

void checkRelation(Rational &r1, Rational &r2) {
    if (r2 < r1) {
        cout << r1 << " is less than " << r2 << endl;
    }
    if (r2 > r1) {
        cout << r1 << " is bigger than " << r2 << endl;
    }
    if (r2 <= r1) {
        cout << r1 << " is less or equal to " << r2 << endl;
    }
    if (r2 >= r1) {
        cout << r1 << " is bigger or equal to " << r2 << endl;
    }
    if (r2 != r1) {
        cout << r1 << " is unequal to " << r2 << endl;
    }
    if (r2 == r1) {
        cout << r1 << " is equal to " << r2 << endl;
    }
}

int main() {
    Rational r1(5,3);
    Rational r2(4,7);
    Rational rResultAdd;
    Rational rResultSub;
    Rational rResultMult;
    Rational rResultDiv;
    rResultAdd = r1 + r2;
    rResultSub = r1 - r2;
    rResultMult = r1 * r2;
    rResultDiv = r1 / r2;
    cout << rResultAdd << endl;
    cout << rResultSub << endl;
    cout << rResultMult << endl;
    cout << rResultDiv << endl;
    checkRelation(r1,r2);
    return 0;
}
