/* Review: 08.08.2020
Umwandlung von Aufgabe 1 deleteEverySecond Vektoren
Implementieren Sie eine Methode, die jedes zweite Element aus dem Vektor löscht. Platz- und laufzeiteffizient

Kelb Review:
deleteStartEnd für Vektoren ist zu kompliziert. Sie kopieren die
Elemente vor dem Start vom Index i zum Index i. Da passiert nichts. Sie
müssen erst nach end beginnen, die Elemente bis zum Ende zu kopieren,
und zwar end+1 wird auf start kopiert, end+2 auf start+1 usw.
*/

#include <iostream>
using namespace std;

class Vector {

private:

    unsigned m_S = 1;
    unsigned m_N = 0;
    int *m_pField = new int[m_S];

public:
    friend ostream &operator<<(ostream &os, const Vector &vec) {
        for(unsigned i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        return os;
    }
    //Zugriffsoperator
    int& operator[](unsigned idx) {
        return m_pField[idx];
    }
    //Zugriffsoperator
    const int& operator[](unsigned idx) const {
        return m_pField[idx];
    }
    //push_back
    void push_back(int i) {
        if (m_N >= m_S)
            resize();
        m_pField[m_N++] = i;
    }
    void pop_back() {
        --m_N;
        if(m_N <= (m_S/2)) {
            const unsigned cNewSize = m_S/2;
            int* pNewObjects = new int[cNewSize];
            for(unsigned i = 0; i < cNewSize; ++i)
                pNewObjects[i] = m_pField[i];
            delete [] m_pField;
            m_S = cNewSize;
            m_pField = pNewObjects;
            pNewObjects = nullptr;
        }
    }
    void deleteStartEnd(unsigned start, unsigned end) {
        for(unsigned j = end + 1, idx = 0; j < m_N; ++j) {
            m_pField[start + idx] = m_pField[end + 1 + idx];
            ++idx;
        }
        m_N -= end - start + 1;
    }
    //size
    unsigned size() const {
        return m_N;
    }
private:

    void resize() {
        const unsigned cNewSize = m_S * 2;
        int* pNewObjects = new int[cNewSize];
        for(unsigned i = 0; i < m_S; ++i)
            pNewObjects[i] = m_pField[i];
        delete [] m_pField;
        m_S = cNewSize;
        m_pField = pNewObjects;
        pNewObjects = nullptr;
    }
};

int main() {
    Vector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(9);
    vec1.push_back(10);
    vec1.push_back(11);
    cout << vec1 << endl;
    vec1.deleteStartEnd(4, 8);
    cout << vec1 << endl;
    return 0;
}
