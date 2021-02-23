/*
 SS2020 Teil1 - Aufgabe 4:
Erweitern Sie den gegebenen Vektor für int Werte um den Operator
friend Vector operator+(const Vector& v1, const Vector& v2), der die beiden Vektoren v1 und v2 konkateniert
(aneinanderhängt), und die Methode pop_back, die das letzte Element entfernt. Dabei soll die pop_back Methode
ein analoges Verhalten bzgl. des Speicherverhaltens zeigen wie die push_back Methode, d.h. wenn die Anzahl der
freien Elemente größer wird als die Reallokationsstrategie vorgibt, soll der Speicher auch freigegeben werden.
Beispiel: Wäre die Reallokationsstrategie die Verdopplung, die Kapazität 20 und pop_back würde das 10. Element
entfernen, so dass nur noch 9 Elemente in dem Vektor gespeichert wären, so müsste ein neuer Speicher
mit nur noch 10 Elementen angelegt werden.
 
class Vector {
public:
     Vector(unsigned uiInitialCapacity = 1, unsigned uiCapacityIncrement = 0) :
     m_cuiIncWidth(uiCapacityIncrement),
     m_uiCapacity(uiInitialCapacity),
     m_pField(new int[m_uiCapacity]) {
     
     }
     
     int operator[](unsigned uiIndex) const;
     int& operator[](unsigned uiIndex);
     void push_back(int i);
 
private:
    const unsigned m_cuiIncWidth;
    unsigned m_uiCapacity;
    unsigned m_uiNextFree = 0;
    int* m_pField;
 
 --> Meine Aufgabe:
 
 */

#include <iostream>
using namespace std;

friend Vector operator +(const Vector& vec1, const Vector& vec2) {
    Vector newVec;
    unsigned ui1 = 0;
    unsigned ui2 = 0;
    while (ui1 < v1.m_uiNextFree) {
        newVec.push_back(v1.m_pField[ui1++]);
    }
    while (ui2 < v2.m_uiNextFree) {
        newVec.push_back(v2.m_pField[ui2++]);
    }
    return newVec;
}

void push_back(int i) {
    if (m_uiNextFree >= m_uiCapacity) {
        resize();
    }
    m_pField[m_uiNextFree++] = i;
}

void resize() {
    const unsigned newSize = m_cuiIncWidth == 0 ? m_uiCapacity * 2 : m_cuiIncWidth + m_uiCapacity;
    int *newField = new int[newSize];
    for (unsigned ui = 0; ui < m_uiCapacity; ++ui) {
        newField[ui] = m_pField[ui];
    }
    delete[] m_pField;
    m_uiCapacity = newSize;
    m_pField = newField;
    newField = nullptr;
}

void pop_back() {
    --m_uiNextFree;
    if(m_uiNextFree <= m_uiCapacity / 2) {
        const unsigned newSize = m_uiCapcity / 2;
        int *newField = new int[newSize];
        for (unsigned ui = 0; ui m_uiNextFree; ++ui) {
            newField[ui] = m_pField[ui];
        }
        delete[] m_pField;
        m_uiCapacity = newSize;
        m_pField = newField;
        newField = nullptr;
    }
}
