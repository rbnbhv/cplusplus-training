/*
 15.06.2020 - Ruben Allenstein
 Aufgabe 2:
 Wiederholen Sie die erste Aufgabe jedoch für komplexe Zahlen.
 */

#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int imag;
    
public:
    Complex() {
        real = 0;
        imag = 0;
    }
    
    Complex(int r, int i) {
        real = r;
        imag = i;
    }
        
    ~Complex() {
        cout << "Destruktor von Complex" << endl;
    }

    friend ostream& operator<<(ostream &os, Complex &c) {
        os << c.real << " + " << c.imag << "i " << endl;
        return os;
    }
    
    // Als friend eintragen, um Zugriff auf private Elemente zu erhalten
    friend Complex operator + (const Complex& c1, const Complex& c2) {
        return Complex(c1.real + c2.real, c1.imag + c2.imag);
    }
};

int main() {
    /*
     Complex c1(12,8);
     Complex c2(11,4);
     Complex c3;
     c3 = c1 + c2;
     cout << c3;
     */
    Complex *c1 = new Complex(12,8);
    Complex *c2 = new Complex(11,4);
    Complex *c3 = new Complex();
    *c3 = *c1 + *c2;
    cout << *c3;
    return 0;
}
