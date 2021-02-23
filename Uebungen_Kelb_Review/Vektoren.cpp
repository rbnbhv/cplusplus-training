/*
 16.07.2020 - Ruben Allenstein
 Blatt 6 - Aufgabe 1:
 Implementieren Sie eine Vektorklasse für rationale Zahlen. Fügen Sie der Implementierung eine push_front Methode hinzu,
 die am Anfang des Vektors ein neues Element hinzufügt. Denken Sie an den Destruktor, Copykonstruktor und Zuweisungsoperator.
 
 ***********************************************************************************************
 
 Kelb Review:
 das sieht besser aus. Beim Kopieren im Copykonstruktor und
 Zuweisungsoperator sollten Sie aber nur bis m_N und nicht bis
 m_uiCapacity kopieren, da nach m_N ja keine gültigen Elemente
 gespeichert sind.
 
 Beim push_front legen Sie immer noch ein neues Array an. Das ist
 ineffizient. Da Sie bereits zum Anfang von push_front eventuell ein
 resize aufrufen, ist garantiert genug Platz, um ein weiteres Element im
 Array zu speichern. Sie müssen nur die Elemente in dem vorhandenen Array
 umspeichern, sprich alle Elemente um eine Position nach hinten schieben.
 
 */

#include <iostream>
using namespace std;

class Rational {
    
private:
    int zaehler;
    unsigned nenner;
    
    int ggT(int z, int n) {
        return n == 0 ? z : ggT(n, z % n);
    }
    
public:
    Rational(int z = 0, unsigned n = 1) : zaehler(z), nenner(n) {
        int g = ggT(z, n);
        zaehler /= g;
        nenner /= g;
    }
    
    friend ostream &operator<<(ostream &os, const Rational &r) {
        if(r.nenner == 1) {
            os << r.zaehler;
        } else {
            os << r.zaehler << "/" << r.nenner;
        }
        return os;
    }
};

class Vector {
private:
    const unsigned m_W;
    unsigned m_S;
    unsigned m_N = 0;
    Rational *m_pField = nullptr;
    
public:
    Vector(unsigned s = 1,unsigned w = 0) : m_W(w), m_S(s), m_pField(new Rational[m_S]) {
    }
    
    Vector(const Vector &vec) : m_W(vec.m_W), m_S(vec.m_S), m_N(vec.m_N) {
        copyHelper(vec);
    }
    
    ~Vector(){
        delete[] m_pField;
    }
    
    void copyHelper(const Vector &vec) {
        m_pField = new Rational[m_S];
        for(unsigned i = 0; i < m_N; ++i) {
            m_pField[i] = vec.m_pField[i];
        }
    }
    
    Vector& operator =(const Vector &vec) {
        if(this == &vec) {
            return *this;
        }
        delete[] m_pField;
        m_S = vec.m_S;
        m_N = vec.m_N;
        m_pField = new Rational[m_S];
        copyHelper(vec);
        return *this;
    }
    
    friend ostream &operator<<(ostream &os, const Vector &vec) {
        for(unsigned i = 0; i < vec.m_N; ++i) {
            os << vec.m_pField[i] << "  ";
        }
        return os;
    }
    
    void push_front(const Rational &r) {
        if(m_N++ >= m_S) {
            resize();
        }
        for(unsigned i = m_N; i >= 1; --i) {
            m_pField[i] = m_pField[i-1];
        }
        m_pField[0] = r;
    }
    
    void push_back(const Rational &r) {
        if (m_N >= m_S)
            resize();
        m_pField[m_N++] = r;
    }
    
private:
    void resize() {
        const unsigned newSize = m_W == 0 ? m_S * 2 : m_S + m_W;
        Rational* newField = new Rational[newSize];
        for(unsigned ui = 0;ui < m_S;++ui) {
            newField[ui] = m_pField[ui];
        }
        delete [] m_pField;
        m_S = newSize;
        m_pField = newField;
        newField = nullptr;
    }
};

int main() {
    Rational r1(4,5);
    Rational r2(5, 1);
    Rational r3(-4,5);
    Rational r4(4,36);
    Rational r5(1, 2);
    Vector vec1;
//Vector vec(4, 5);
    vec1.push_front(r1);
    vec1.push_front(r2);
    vec1.push_front(r3);
    vec1.push_front(r3);
    vec1.push_front(r3);
    //    vec.push_back(r2);
    //    vec.push_back(r3);
    //    vec.push_back(r4);
    //    vec.push_back(r5);
    //    Vector vec5(vec1);
    //    Vector vec6 = vec5;
    cout << vec1 << endl;
    //    cout << vec5 << endl;
    //    cout << vec6 << endl;
    return 0;
}
