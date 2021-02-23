/*
14.08.2020 - Ruben Allenstein
Aufgabe 1:
Stellen Sie die Implementierung von Vektoren, Listen, Bäumen und Hashtabelle auf Templates um.

 Frage:
 wir hatten übungstechnisch bisher nur wenig Berührungspunkte mit Templates.
 Wir hatten hier auf den ersten Blick keine Probleme und fragen Sie lieber ob die Umstellung auf Templates hier auch wirklich
 gelungen ist - wir haben bewusst nur die Vektorklasse umgestellt.
 
 Antwort:
 sieht gut aus
*/

#include <iostream>
#include <string>

using namespace std;

class MyExceptionEmpty : public exception {
  virtual const char* what() const throw() {
    return "Vector is empty!";
  }
};

class MyExceptionOutOfBound: public exception {
  virtual const char* what() const throw() {
    return "Out of bound!";
  }
};

template<class T>
class Vector {

private:

    const unsigned m_cuiIncWidth;
    unsigned m_uiCapacity;
    unsigned m_uiNextFree = 0;
    T *m_pField = nullptr;

public:

    Vector(unsigned uiInitialCapacity = 1, unsigned uiCapacityIncrement = 0) : m_cuiIncWidth(uiCapacityIncrement), m_uiCapacity(uiInitialCapacity), m_pField(new T[m_uiCapacity]) {

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
        m_pField = new T[m_uiCapacity];
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
    void push_front(T val) {
        if (m_uiNextFree >= m_uiCapacity)
            resize();
        for(unsigned i = m_uiNextFree; i >= 1; --i) {
            m_pField[i] = m_pField[i-1];
        }
        m_pField[0] = val;
        ++m_uiNextFree;
    }
    void push_back(T val) {
        if (m_uiNextFree >= m_uiCapacity)
            resize();
        m_pField[m_uiNextFree++] = val;
    }
    void pop_front() {
        if(m_uiNextFree == 0) { //da unsigned int
            throw MyExceptionEmpty();
        } else {
            for(unsigned i = 1; i <= m_uiNextFree; ++i) {
                m_pField[i-1] = m_pField[i];
            }
            --m_uiNextFree;
        }
    }
    void pop_back() {
        if(m_uiNextFree == 0) { //da unsigned int
            throw MyExceptionEmpty();
        } else {
            --m_uiNextFree;
        }
    }
    T front() {
        if(m_uiNextFree == 0) { //da unsigned int
            throw MyExceptionEmpty();
        } else {
            return m_pField[0];
        }
    }
    T back() {
        if(m_uiNextFree == 0) { //da unsigned int
            throw MyExceptionEmpty();
        } else {
            return m_pField[m_uiNextFree-1];
        }
    }
    T& operator[](unsigned uiIndex) {
        if(uiIndex >= size()) {
            throw MyExceptionOutOfBound();
        } else {
            return m_pField[uiIndex];
        }
    }
    const T& operator[](unsigned uiIndex) const {
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
        T* pNewObjects = new T[cuiNewSize];
        for(unsigned ui = 0;ui < m_uiCapacity;++ui)
            pNewObjects[ui] = m_pField[ui];
        delete [] m_pField;
        m_uiCapacity = cuiNewSize;
        m_pField = pNewObjects;
        pNewObjects = nullptr;
    }
};

int main() {
    Vector<string> vec1;
    vec1.push_back("Hallo");
    vec1.push_back("Juhu");
    vec1.push_back("Super");
    vec1.push_back("Top");
    vec1.push_back("Besser");
    vec1.push_back("Schoen");
    cout << vec1 << endl;
    cout << vec1.front() << endl;
    cout << vec1.back() << endl;
    vec1.pop_back();
    vec1.pop_back();
    cout << vec1 << endl;
//    cout << vec1.front() << endl;
    cout << vec1[3] << endl;
    return 0;
}
