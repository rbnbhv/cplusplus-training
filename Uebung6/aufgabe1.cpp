/*
 15.06.2020 - Ruben Allenstein
 Aufgabe 1:
 Implementieren Sie eine Vektorklasse für rationale Zahlen. Fügen Sie der Implementierung eine push_front Methode hinzu,
 die am Anfang des Vektors ein neues Element hinzufügt. Denken Sie an den Destruktor, Copykonstruktor und Zuweisungsoperator.
 */

#include <iostream>

using namespace std;

class Rational {
private:
    int zaehler;
    unsigned nenner;
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
    
    friend ostream& operator<<(ostream& os, Rational &r) {
        if (r.nenner == 1) {
            os << r.zaehler << endl;
        }
        else {
            os << r.zaehler << " / " << r.nenner;
        }
        return os;
    }
};

class RatioVector {
private:
    void resize() {
        //Neue Größe, abhängig von Incrementstrategie
        const unsigned cuiNewSize = m_cuiIncWidth == 0 ? m_uiCapacity * 2 : m_uiCapacity + m_cuiIncWidth; // wenn 0, dann verdoppeln, ansonsten um m_cuiIncWidth erhöhen
        //Array mit neuer Größe erzeugen
        Rational *pNewObjects = new Rational[cuiNewSize];
        //Alte Daten in neues Array kopieren
        for (unsigned ui = 0; ui < m_uiCapacity; ++ui) {
            pNewObjects[ui] = m_pField[ui];
        }
        // Altes Feld löschen
        delete[] m_pField;
        //Neue Größe in Objekt speichern
        m_uiCapacity = cuiNewSize;
        //Pointer m_pfield auf neues Array zeigen
        m_pField = pNewObjects;
    }
    
    const unsigned m_cuiIncWidth;
    unsigned m_uiCapacity;
    unsigned m_uiNextFree = 0;
    Rational *m_pField;

public:
    RatioVector() : m_cuiIncWidth(0){
        m_uiCapacity = 1;
        m_pField = nullptr;
    }

    RatioVector(unsigned uiInitialCapacity, unsigned uiCapacityIncrement) : m_cuiIncWidth(uiCapacityIncrement) {
        m_uiCapacity = uiInitialCapacity;
        m_pField = new Rational[m_uiCapacity];
    }

    RatioVector(const RatioVector &crArg) : m_cuiIncWidth(crArg.m_cuiIncWidth), m_uiCapacity(crArg.m_uiCapacity), m_uiNextFree(crArg.m_uiNextFree), m_pField(crArg.m_pField) {
        for (unsigned ui = 0; ui < crArg.m_uiCapacity; ++ui) {
            m_pField[ui] = crArg[ui];
        }
    }

    ~RatioVector() {
        delete[] m_pField;
    }

    friend ostream &operator<<(ostream &os, const RatioVector &crArg) {
        for (unsigned ui = 0; ui < crArg.m_uiCapacity; ++ui) {
            os << crArg.m_pField[ui] << " " ;
        }
        return os;
    }

    RatioVector &operator=(const RatioVector &crArg) {
        if (&crArg != this) {
            delete[] m_pField;
            m_pField = new Rational[crArg.m_uiCapacity];
            for (unsigned ui = 0; ui <m_uiCapacity; ++ui) {
                m_pField[ui] = crArg.m_pField[ui];
            }
        }
        return *this;
    }

    Rational operator[](unsigned uiIndex) const {
        return m_pField[uiIndex];
    }

    Rational &operator[](unsigned uiIndex) {
        return m_pField[uiIndex];
    }

    void push_back(const Rational &crArg) {
        if (m_uiNextFree >= m_uiCapacity) {
            resize();
        }
        m_pField[m_uiNextFree++] = crArg;
    }

    void push_front(const Rational &crArg) {
        if (m_uiNextFree++ >= m_uiCapacity) {
            resize();
        }
        //Neues Array mit gleicher Größe anlegen
        Rational *pNewObject = new Rational[m_uiCapacity];

        //Objekte kopieren, bei Index 1 starten
        for (unsigned ui = 0; ui < m_uiCapacity; ++ui) {
            pNewObject[ui + 1] = m_pField[ui];
        }
        pNewObject[0] = crArg;
        delete [] m_pField;
        m_pField = pNewObject;
    }
};

int main() {
    Rational a(3,4);
    Rational b(5,9);
//    Rational add = a + b;
//    Rational sub = a - b;
//    Rational mult = a * b;
//    Rational div = a / b;
//    cout << a << endl << b << endl << add << endl << sub << endl << mult << endl << div << endl;
    Rational field[3] = {Rational(2,3), Rational(4,8), Rational(1,4)};
    for (unsigned ui = 0; ui < 3; ++ui) {
        cout << field[ui] << " " ;
    }
    cout << endl;
    for (unsigned ui = 0; ui < 3; ++ui) {
        cout << field[ui] << " ";
    }
    cout << endl;
    
    cout << "Wird ein Test: " << endl;
    RatioVector vec1;
    vec1.push_front(a);
  
    cout << vec1 << " das ist vec 1 gewesen " <<endl;
    return 0;
}
