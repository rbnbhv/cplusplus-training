/* Review: 04.08.2020
Vektor:
- Jedes Listenelement, dass den Wert i gespeichert hat, soll gelöscht werden. --> deleteMatch(int i)
- Speicher- und Laufeffizient
- fehlende Operatoren und Methoden hinzufügen

Frage:
(Problem war in deleteMatch)
ich denke wir haben es verstanden.
Wir speichern zunächst p in tmp und setzen danach p auf dessen Nachfolger.
Wir prüfen beim Match ob tmp->m_i == i entspricht und falls ja, löschen wir tmp, haben aber mit p stets einen Vorsprung um einen
Nachfolger.
 
 antwort:
 so ist es richtig. tmp = nullptr muss nicht sein, weil am Ende der while
 Schleife tmp eh verschwindet und in jeder Iteration neu angelegt und
 initialisiert wird.
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
        E* m_P = nullptr;
        E* m_N = nullptr;
    };
    
public:
    friend ostream& operator<<(ostream& os, const L& crArg) {
        if (crArg.m_Head)
            os << *crArg.m_Head;
        return os;
    }
    
    void deleteMatch(int i) {
        E* p = m_Head;
        while(p) {
            E* tmp = p;
            p = p->m_N;
            if(tmp->m_i == i) {
                if(tmp == m_Head) {
                    m_Head = tmp->m_N;
                }
                if(tmp->m_N){
                    tmp->m_N->m_P = tmp->m_P;
                }
                if(tmp->m_P) {
                    tmp->m_P->m_N = tmp->m_N;
                }
                if(tmp == m_Tail) {
                    m_Tail = tmp->m_P;
                }
                delete tmp;
                tmp = nullptr;
            }
        }
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
    doubleList.deleteMatch(8);
    cout << doubleList << endl;
    return 0;
}
