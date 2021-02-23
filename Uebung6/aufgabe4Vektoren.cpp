/*
15.06.2020 - Ruben Allenstein
 Aufgabe 4:
 Erweitern Sie die Implementierungen von Vektoren und Listen um eine pop_front und pop_back Methode, die das
 erste bzw. letzte Element entfernt.

 Frage:
 der Ausgabeoperator wurde nochmals angepasst, entsprechend den Programmen der Altklausuren.
 Jetzt ist der zweite Zugriffsoperator const Rational& operator[] auch zum Einsatz gekommen.
 Ich denke, man braucht den const Zugriffsoperator um Konstante Objekte auszugeben?
 
 Antwort:
 Nicht auszugeben, aber um überhaupt einen Zugriff auf die Elemente zu haben.
 */



#include <iostream>
using namespace std;

class Rational {

private:

    int zaehler;
    unsigned nenner;

    unsigned ggT(int z, int n) {
       return n == 0 ? z : ggT(n, z % n);
    }

public:

    Rational(int z = 0, unsigned n = 1) : zaehler(z), nenner(n) {
        unsigned g = ggT(zaehler, nenner);
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

    const unsigned m_cuiIncWidth;
    unsigned m_uiCapacity;
    unsigned m_uiNextFree = 0;
    Rational *m_pField = nullptr;

public:

    Vector(unsigned uiInitialCapacity = 1, unsigned uiCapacityIncrement = 0) : m_cuiIncWidth(uiCapacityIncrement), m_uiCapacity(uiInitialCapacity), m_pField(new Rational[m_uiCapacity]) {

    }

    Vector(const Vector &vec) : m_cuiIncWidth(vec.m_cuiIncWidth), m_uiCapacity(vec.m_uiCapacity), m_uiNextFree(vec.m_uiNextFree) {
        copyHelper(vec);
    }
    ~Vector(){
        delete[] m_pField;
    }
    Vector &operator=(const Vector &vec) {
        if(this == &vec)
            return *this;
        delete[] m_pField;
//        m_cuiIncWidth = vec.m_cuiIncWidth;
        m_uiCapacity = vec.m_uiCapacity;
        m_uiNextFree = vec.m_uiNextFree;
        copyHelper(vec);
        return *this;
    }
    void copyHelper(const Vector &vec) {
        m_pField = new Rational[m_uiCapacity];
        for(unsigned i = 0; i < m_uiNextFree; ++i) {
            m_pField[i] = vec.m_pField[i];
        }
    }
    friend ostream &operator<<(ostream &os, const Vector &vec) {
        for(unsigned i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        return os;
    }
    void push_front(const Rational &r) {
        if (m_uiNextFree >= m_uiCapacity)
            resize();
        for(unsigned i = m_uiNextFree; i >= 1; --i) {
            m_pField[i] = m_pField[i-1];
        }
        m_pField[0] = r;
        ++m_uiNextFree;
    }
    void push_back(const Rational &r) {
        if (m_uiNextFree >= m_uiCapacity)
            resize();
        m_pField[m_uiNextFree++] = r;
    }
    void pop_front() {
        for(unsigned i = 1; i <= m_uiNextFree; ++i) {
            m_pField[i-1] = m_pField[i];
        }
        --m_uiNextFree;
    }
    void pop_back() {
        m_pField[m_uiNextFree-1] = m_pField[m_uiNextFree];
        --m_uiNextFree;
    }
    Rational& operator[](unsigned uiIndex) {
//        assert(uiIndex < uiLength);
//        assert(uiIndex < m_uiNextFree);
        return m_pField[uiIndex];
    }
    const Rational& operator[](unsigned uiIndex) const {
//        assert(uiIndex < uiLength);
//        assert(uiIndex < m_uiNextFree);
        return m_pField[uiIndex];
    }
//    unsigned int size() const {
//        return uiLength;
//    }
    unsigned size() const {
        return m_uiNextFree;
    }
private:

    void resize() {
        const unsigned cuiNewSize = m_cuiIncWidth==0 ? m_uiCapacity * 2 : m_uiCapacity + m_cuiIncWidth;
        Rational* pNewObjects = new Rational[cuiNewSize];
        for(unsigned ui = 0;ui < m_uiCapacity;++ui)
            pNewObjects[ui] = m_pField[ui];
        delete [] m_pField;
        m_uiCapacity = cuiNewSize;
        m_pField = pNewObjects;
        pNewObjects = nullptr;
    }
};

int main() {
    Rational r1(4,5);
    Rational r2(5, 1);
    Rational r3(-4,5);
    Rational r4(4,36);
    Rational r5(1, 2);
    Vector vec1;
    vec1.push_back(r1);
    cout << "Vec1: " << vec1 << endl;
    vec1.push_back(r2);
    cout << "Vec1: " << vec1 << endl;
    vec1.push_back(r3);
    cout << "Vec1: " << vec1 << endl;
    Vector vec2(vec1);
    cout << "Vec2: " << vec2 << endl;
    vec1.push_back(r4);
    vec1.push_back(r5);
    cout << "Vec1: " << vec1 << endl;
    cout << "Vec2: " << vec2 << endl;
    Vector vec3;
    vec3.push_front(r1);
    cout << "Vec3: " << vec3 << endl;
    vec3.push_front(r2);
    cout << "Vec3: " << vec3 << endl;
    vec3.push_front(r3);
    cout << "Vec3: " << vec3 << endl;
    vec3 = vec1;
    cout << "Vec3: " << vec3 << endl;
    vec3.pop_front();
    cout << "Vec3: " << vec3 << endl;
    vec3.pop_back();
    cout << "Vec3: " << vec3 << endl;
    vec1.pop_back();
    vec1.pop_back();
    cout << "Vec1: " << vec1 << endl;
    cout << vec1[2] << endl;
    cout << vec1.size() << endl;
    for(unsigned i = 0; i < vec1.size(); ++i) {
        vec1[i] = i;
    }
    cout << vec1 << endl;
    return 0;
}
