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
    friend ostream &operator<<(ostream &strm, const Rational &r) {
        if(r.nenner == 1) {
            strm << r.zaehler;
        } else {
            strm << r.zaehler << "/" << r.nenner;
        }
        return strm;
    }
};

class Vector {
private:
    const unsigned m_cuiIncWidth;
    unsigned m_uiCapacity;
    unsigned m_uiNextFree = 0;
    Rational *m_pField;

public:

    Vector(unsigned uiInitialCapacity = 1,unsigned uiCapacityIncrement = 0) :
        m_cuiIncWidth(uiCapacityIncrement),
        m_uiCapacity(uiInitialCapacity),
        m_pField(new Rational[m_uiCapacity]) {
    }

    Vector(const Vector &vec) : m_cuiIncWidth(vec.m_cuiIncWidth), m_uiCapacity(vec.m_uiCapacity) {
        m_pField = new Rational[m_uiCapacity];
        for(unsigned i = 0; i < m_uiCapacity; ++i) {
            m_pField[i] = vec.m_pField[i];
        }
    }
    ~Vector(){
        delete[] m_pField;
    }
    Vector &operator=(const Vector &vec) {
        if(this != &vec) {
            delete[] m_pField;
            m_uiCapacity = vec.m_uiCapacity;
            m_pField = new Rational[m_uiCapacity];
            for(unsigned i = 0; i < m_uiCapacity; ++i) {
                m_pField[i] = vec.m_pField[i];
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &strm, const Vector &vec) {
        for(unsigned i = 0; i < vec.m_uiCapacity; ++i) {
            strm << vec.m_pField[i] << "  ";
        }
        return strm;
    }
    void push_front(const Rational &r) {
        if(m_uiNextFree++ >= m_uiCapacity)
            resize();
        Rational *vTmp = new Rational[m_uiCapacity];
        for(unsigned i = 0; i < m_uiCapacity; ++i) {
               vTmp[i + 1] = m_pField[i];
        }
        vTmp[0] = r;
        delete[] m_pField;
        m_pField = vTmp;
        vTmp = nullptr;
    }
    void push_back(const Rational &r) {
        if (m_uiNextFree >= m_uiCapacity)
            resize();
        m_pField[m_uiNextFree++] = r;
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
//    Vector vec(4, 5);
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
