/* Review: 09.08.2020
Aufgabe 1: deleteEverySecond LinkedList
Implementieren Sie eine Methode, die jedes zweite Element aus der LinkedList löscht. Platz- und laufzeiteffizient

Kelb Review:
deleteStartEnd für Listen ist auch zu kompliziert. Sie haben eine
Schleife, die alles erledigen soll. Dabei haben Sie unterschiedliche
Phasen, die die Methode abarbeiten muss. Die würde ich auch als einzelne
Phasen programmieren. In der ersten Phase, findet man den Vorgänger von
start, in der zweiten Phase findet man den Nachfolger von end und löscht
alle Elemente von start bis dahin, in der dritten Phase hängt man den
Nachfolger des Vorgängers von start auf den Nachfolger von end. Fertig.
 
 Antwort:
 deleteStartEnd für LL haben wir ebenfalls verändert. Es ist etwas einfacher zu lesen, aber nicht viel kompakter, wir hatten
 besonders Schwierigkeiten, wenn start bei 0 anfängt und man damit m_pHead sowie prev ändern musste.
 
 */

#include <iostream>
using namespace std;

class LinkedList {
    struct ListElem {
        ListElem* m_pNext = nullptr;
        int m_iCont;

        ListElem(int iElem, ListElem* pNext) : m_pNext(pNext), m_iCont(iElem) {

        }
        friend ostream& operator<<(ostream& os, const ListElem& crArg) {
            os << crArg.m_iCont << " ";
            if (crArg.m_pNext)
                os << *crArg.m_pNext;
            return os;
        }
    };
private:
    ListElem* m_pHead = nullptr;
    ListElem* m_pTail = nullptr;

public:
    LinkedList() {

    }
    LinkedList(const LinkedList &llist) {
        copyHelper(llist);
    }
    ~LinkedList() {
        destroy();
    }
    LinkedList &operator=(const LinkedList &llist) {
        if(this == &llist)
            return *this;
        destroy();
        copyHelper(llist);
        return *this;
    }
    void copyHelper(const LinkedList &llist) {
        ListElem* p = llist.m_pHead;
        while(p) {
            this->push_back(p->m_iCont);
            p = p->m_pNext;
        }
    }
    void destroy() {
        ListElem *p = nullptr;
        while(m_pHead) {
            p = m_pHead->m_pNext;
            delete m_pHead;
            m_pHead = p;
        }
        m_pTail = nullptr;
    }
    friend ostream& operator<<(ostream& os, const LinkedList& crArg) {
        if (crArg.m_pHead)
            os << *crArg.m_pHead;
        return os;
    }
    void push_front(int iElem) {
        m_pHead = new ListElem(iElem, m_pHead);
        if(!m_pTail)
            m_pTail = m_pHead;
    }
    void push_back(int iElem) {
        ListElem *node = new ListElem(iElem, nullptr);
        if(!m_pHead)
            m_pHead = m_pTail = node;
        else {
            m_pTail->m_pNext = node;
            m_pTail = m_pTail->m_pNext;
        }
    }
    void deleteStartEnd(int start, int end) {
        ///counter, Hilfsvariable zum Vergleich für start und end
        int count = 0;
        ///p, Hilfsvariable zum Durchlaufen der Liste
        ListElem* p = m_pHead;
        ListElem* prev = nullptr;
        ListElem* next = nullptr;
        ///1Phase - es wird der Vorgänger (prev) von start in der Liste gesucht
        while(p && count < start) {
            prev = p;
            p = p->m_pNext;
            ++count;
        }

        // 2Phase - es wird der Nachfolger (next) von end in der Liste gesucht,
        // dabei werden alle Knoten von start bis end gelöscht
/* Antwort von Kelb: next ist immer gleich p nach der zweiten Schleife. Daher können Sie next weglassen und durch p ersetzen. Der Rest passt. Viele Grüße, Peter Kelb
*/
         while(p && count <= end) {
            ListElem* tmp = p;
            p = p->m_pNext;
            ++count;
            p = tmp->m_pNext;
            delete tmp;
        }
        ///3Phase mit Beachtung zweierlei Sonderfälle
        ///1 Sonderfall - Head wird einfach neu initialisiert und damit lokalisiert
        if(start == 0) {
            m_pHead = next;
        ///2 Sonderfall - Tail wird einfach neu initialisiert und damit lokalisiert, dabei muss der Nachfolger ein nullptr sein
        } else if(!p) {
            m_pTail = prev;
            m_pTail->m_pNext = nullptr;
        ///Regulärer Ablauf - man hängt den Nachfolger des Vorgängers von start auf den Nachfolger von end
        } else {
            prev->m_pNext = next;
        }
    }
    int front() {
        return m_pHead->m_iCont;
    }
    int back() {
        return m_pTail->m_iCont;
    }
};

int main() {
    LinkedList list0;
    list0.push_back(1);
    list0.push_back(2);
    list0.push_back(3);
    list0.push_back(4);
    list0.push_back(5);
    list0.push_back(6);
    cout << list0 << endl;
    list0.deleteStartEnd(3, 5);
    cout << list0 << endl;
    cout << list0.front() << endl;
    cout << list0.back() << endl;
    return 0;
}
