/* Review: 12.08.2020
Aufgabe 1: Vektor
Implementieren Sie die Klassenmethode merge, die zwei sortierte Vektoren übergeben bekommt und eine sortierten Vektor
 zurückliefert, der alle Elemente der beiden Vektoren enthält. Die Laufzeit soll linear zu der Größen der übergebenen Vektoren
 sein.
 
 Frage:
 Befindet sich merge auch in Ihrem Vorstellungsbereich? Wir haben hier nicht wirklich einen Vektor zurückgegeben sondern ein
 int*, was ja aber eigentlich auch hinter einem Vektor steckt.

 Antwort von Kelb:
 prinzipiell funktioniert merge so, wie ich mir das gewünscht habe. Sie
 haben jedoch eine globale Funktion definiert, es sollte aber eine
 Klassenmethode sein. Der Rückgabe Typ sollte schon Vektor sein. Die
 Klasse ist ja auch vorgegeben und Sie können einfach mit push_back die
 Elemente am Ende hinzufügen. Dann brauchen Sie auch den Index k nicht mehr.
 
 Kelb Review:
 Ja, besser. Jedoch wird der Ergebnis Vektor nicht auf dem Heap erzeugt.
 Der wird ja sonst nie wieder freigegeben. Also statt

 Vector *v = new Vector;

 legt man den Ergebnisvektor statisch an:
 Vector v;
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

Vector merge(const Vector &v1, const Vector &v2) {
    unsigned i = 0;
    unsigned j = 0;
    Vector v;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            v.push_back(v1[i++]);
        } else {
            v.push_back(v2[j++]);
        }
    }
    while (i < v1.size()) {
        v.push_back(v1[i++]);
    }
    while (j < v2.size()) {
        v.push_back(v2[j++]);
    }
    return v;
}

int main() {
    Vector vec1;
    vec1.push_back(0);
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    cout << vec1 << endl;
    Vector vec2;
    vec2.push_back(0);
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    vec2.push_back(7);
    vec2.push_back(8);
    cout << vec2 << endl;
    cout << merge(vec1, vec2) << endl;
    return 0;
}
