/*
13.08.2020 - Ruben Allenstein
Aufgabe 2:
Fügen Sie der Implementierung von Vektoren und Listen Exceptions hinzu, wenn mittels des []-Operators oder
 der front(), back(), pop_front() bzw. pop_back() Methoden auf illegale Elemente bzw. leere Vektoren / Listen zugegriffen wird.
 
 Frage:
 anbei haben wir für Vektoren und Listen (DLL und LL) Exceptions implementiert.
 Wir fragen uns, ob dies so richtig ist.
 
 Antwort:
 sieht gut aus. Bei dem Vektor prüfen Sie immer m_uiNextFree <= 0. Da
 m_uiNextFree aber ein unsigned int ist, kann er niemals kleiner als 0
 sein. Der Test auf == 0 wäre daher besser.
 */


#include <iostream>
using namespace std;

class MyExceptionEmpty: public exception {
  virtual const char* what() const throw() {
    return "Vector is empty!";
  }
};

class MyExceptionOutOfBound: public exception {
  virtual const char* what() const throw() {
    return "Out of bound!";
  }
};

class Vector {

private:

    const unsigned m_cuiIncWidth;
    unsigned m_uiCapacity;
    unsigned m_uiNextFree = 0;
    int *m_pField = nullptr;

public:

    Vector(unsigned uiInitialCapacity = 1, unsigned uiCapacityIncrement = 0) : m_cuiIncWidth(uiCapacityIncrement), m_uiCapacity(uiInitialCapacity), m_pField(new int[m_uiCapacity]) {

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
        m_pField = new int[m_uiCapacity];
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
    void push_front(int val) {
        if (m_uiNextFree >= m_uiCapacity)
            resize();
        for(unsigned i = m_uiNextFree; i >= 1; --i) {
            m_pField[i] = m_pField[i-1];
        }
        m_pField[0] = val;
        ++m_uiNextFree;
    }
    void push_back(int val) {
        if (m_uiNextFree >= m_uiCapacity)
            resize();
        m_pField[m_uiNextFree++] = val;
    }
    void pop_front() {
        if(m_uiNextFree <= 0) {
            throw MyExceptionEmpty();
        } else {
            for(unsigned i = 1; i <= m_uiNextFree; ++i) {
                m_pField[i-1] = m_pField[i];
            }
            --m_uiNextFree;
        }
    }
    void pop_back() {
        if(m_uiNextFree <= 0) {
            throw MyExceptionEmpty();
        } else {
            --m_uiNextFree;
        }
    }
    int front() {
        if(m_uiNextFree <= 0) {
            throw MyExceptionEmpty();
        } else {
            return m_pField[0];
        }
    }
    int back() {
        if(m_uiNextFree <= 0) {
            throw MyExceptionEmpty();
        } else {
            return m_pField[m_uiNextFree-1];
        }
    }
    int& operator[](unsigned uiIndex) {
        if(uiIndex >= size()) {
            throw MyExceptionOutOfBound();
        } else {
            return m_pField[uiIndex];
        }
    }
    const int& operator[](unsigned uiIndex) const {
        if(uiIndex >= size()) {
            throw MyExceptionOutOfBound();
        } else {
            return m_pField[uiIndex];
        }
    }
    unsigned size() const {
        return m_uiNextFree;
    }
private:

    void resize() {
        const unsigned cuiNewSize = m_cuiIncWidth==0 ? m_uiCapacity * 2 : m_uiCapacity + m_cuiIncWidth;
        int* pNewObjects = new int[cuiNewSize];
        for(unsigned ui = 0;ui < m_uiCapacity;++ui)
            pNewObjects[ui] = m_pField[ui];
        delete [] m_pField;
        m_uiCapacity = cuiNewSize;
        m_pField = pNewObjects;
        pNewObjects = nullptr;
    }
};

int main() {
    Vector vec1;
    vec1.push_back(0);
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    cout << vec1 << endl;
    cout << vec1.front() << endl;
    cout << vec1.back() << endl;
//    vec1.pop_back();
//    vec1.pop_back();
//    vec1.pop_back();
//    vec1.pop_back();
//    vec1.pop_back();
//    vec1.pop_back();
//    cout << vec1 << endl;
//    cout << vec1.front() << endl;
    cout << vec1[3] << endl;
    cout << vec1[6] << endl;
    return 0;
}
