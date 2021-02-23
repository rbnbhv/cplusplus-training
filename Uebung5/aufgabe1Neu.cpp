#include <iostream>

using namespace std;

class Rational {
private:
    unsigned zaehler, nenner;
    
public:
    Rational() {}
    Rational(unsigned int z, unsigned int n) : zaehler{z}, nenner{n} {
        
    };
    
    ~Rational() {
        cout << "Destuktor aufgerufen" << endl;
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
};

int main() {
    Rational *number1 = new Rational(9,13);
    Rational *number2 = new Rational(4,15);
    cout << number1->get_zaehler() + number2->get_zaehler() << "/" << number1->get_nenner() + number2->get_nenner() << endl;
    delete number1;
    delete number2;
    return 0;
}
