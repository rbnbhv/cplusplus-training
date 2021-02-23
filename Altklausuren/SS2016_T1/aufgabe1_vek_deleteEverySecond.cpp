/* Review: 08.08.2020
 Aufgabe 1: deleteEverySecond Vektoren
 Implementieren Sie eine Methode, die jedes zweite Element aus dem Vektor löscht. Platz- und laufzeiteffizient
 
 Kelb Review:
 - deleteEverySecond funktioniert, kann jedoch noch ein wenig vereinfacht werden (siehe Code)
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
    
    // Vorschlag Kelb:
    void deleteEverySecond() {
        unsigned idx = 0;
        for(unsigned j = 0; j < m_N; ++j) {
            if(j % 2 == 0) {
                m_pField[idx++] = m_pField[j];
            }
        }
        m_N = idx;
    }
    
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
    vec1.push_back(0);
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
    vec1.deleteEverySecond();
    cout << vec1 << endl;
    return 0;
}
