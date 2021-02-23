/* Review: 06.08.2020
 Hallo Herr Kelb,
 wir haben die Implementierung eines Iterators für doppelt verkettete Listen probiert. Wir haben hier jedoch fragen. Die
 Methode iterator end() returned iterator(nullptr) und nicht iterator(m_Tail), da es sonst in der for-Schleife in der Main zu
 Problemen kommt. Würde m_Tail zurückgegeben werden, würde das letzte Element in der Schleife ausgelassen werden.
 Was sagen Sie?

 Antwort:
-  iterator(nullptr) ist für die Liste genau richtig. Viele Grüße
 
*/

#include <iostream>
using namespace std;

class L {
    struct E {
        E(unsigned i, E* pN, E* pP) : m_i(i),m_N(pN),m_P(pP) {
            if (m_N)
                m_N->m_P = this;
            if (m_P)
                m_P->m_N = this;
        }
        friend ostream& operator<<(ostream& os,const E& crArg) {
            os << crArg.m_i << " ";
            if (crArg.m_N)
                os << *crArg.m_N;
            return os;
        }
        int m_i;
        E* m_N = nullptr;
        E* m_P = nullptr;
    };
public:
    class iterator {
        E* p;
    public:
        iterator(E* value = nullptr) : p(value) {
        }
        iterator& operator++() { //Preinkrement
            p = p->m_N;
            return *this;
        }
        bool operator != (const iterator& other) {
            return p != other.p;
        }
        int& operator *() {
            return p->m_i;
        }
    };

    iterator begin() {
        return iterator(m_Head);
    }

    iterator end() {
       return iterator(nullptr);

    }
    const iterator begin() const {
        return iterator(m_Head);
    }

    const iterator end() const {
        return iterator(nullptr);
    }
    friend ostream& operator<<(ostream& os, const L& crArg) {
        if (crArg.m_Head)
            os << *crArg.m_Head;
        return os;
    }
    void push_front(int i) {
        m_Head = new E(i, m_Head, nullptr);
        if(!m_Tail)
            m_Tail = m_Head;
    }

private:

    E* m_Head = nullptr;
    E* m_Tail = nullptr;

};

int main() {
    L doubleList;
    doubleList.push_front(888);
    doubleList.push_front(8);
    doubleList.push_front(8);
    doubleList.push_front(6);
    doubleList.push_front(7);
    doubleList.push_front(8);
    doubleList.push_front(4);
    doubleList.push_front(88);
    cout << doubleList << endl;
    for(L::iterator i = doubleList.begin(); i != doubleList.end(); ++i)
        ++(*i);
    cout << doubleList << endl;
    return 0;
}
