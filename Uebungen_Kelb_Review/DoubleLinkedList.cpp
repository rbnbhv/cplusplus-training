/*
 25.07.2020 - Ruben Allenstein
 Blatt 7 - Aufgabe 1:
 Implementieren Sie eine doppelt verkette Liste für unsigned int, die als Methoden push_front (Element am Anfang hinzufügen),
 push_back (Element am Ende hinzufügen), pop_front (erstes Element entfernen), pop_back (letztes Element entfernen),
 front (erstes Element zurückliefern) und back (letztes Element zurückliefern) besitzt. Denken Sie an den Destruktor,
 Copykonstruktor, Zuweisungsoperator und Ausgabeoperator.
 */

#include <iostream>
using namespace std;

class DoubleList {
public:
    struct ListElem {
        unsigned m_iElem;
        ListElem* m_pNext = nullptr;
        ListElem* m_pPrev = nullptr;
        
        ListElem(unsigned i,ListElem* pNext,ListElem* pPrev) :
        m_iElem(i),m_pNext(pNext),m_pPrev(pPrev) {
            if (m_pNext)
                m_pNext->m_pPrev = this;
            if (m_pPrev)
                m_pPrev->m_pNext = this;
        }
        friend ostream& operator<<(ostream& os,const ListElem& crArg) {
            os << crArg.m_iElem << " ";
            if (crArg.m_pNext)
                os << *crArg.m_pNext;
            return os;
        }
    };
    
private:
    ListElem* m_pHead = nullptr;
    ListElem* m_pTail = nullptr;
    
public:
    DoubleList() {
    }
    
    DoubleList(const DoubleList &dl) {
        copyHelper(dl);
    }
    
    ~DoubleList() {
        destructor();
    }
    
    DoubleList &operator=(const DoubleList &dl) {
        if(this == &dl) {
            return *this;
        }
        destructor();
        copyHelper(dl);
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const DoubleList& crArg) {
        if (crArg.m_pHead)
            os << *crArg.m_pHead;
        return os;
    }
    
    void copyHelper(const DoubleList &dl) {
        ListElem *p = dl.m_pHead;
        while(p) {
            this->push_back(p->m_iElem);
            p = p->m_pNext;
        }
    }
    
    void destructor() {
        ListElem *p = nullptr;
        while(m_pHead) {
            p = m_pHead->m_pNext;
            delete m_pHead;
            m_pHead = p;
        }
        m_pTail = nullptr;
    }
    
    void push_front(unsigned i) {
        m_pHead = new ListElem(i, m_pHead, nullptr);
        if (!m_pTail) {
            m_pTail = m_pHead;
        }
    }
    
    void push_back(unsigned i) {
        m_pTail = new ListElem(i, nullptr, m_pTail);
        if (!m_pHead) {
            m_pHead = m_pTail;
        }
    }
    
    void pop_front() {
        ListElem *p = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete p;
        if (m_pHead)
            m_pHead->m_pPrev = nullptr;
        else
            m_pTail = nullptr;
    }
    
    void pop_back() {
        ListElem *p = m_pTail;
        m_pTail = m_pTail->m_pPrev;
        delete p;
        if (m_pTail)
            m_pTail->m_pNext = nullptr;
        else
            m_pHead = nullptr;
    }
    
    unsigned front() {
        return m_pHead->m_iElem;
    }
    
    unsigned back() {
        return m_pTail->m_iElem;
    }
};

int main() {
    DoubleList dList0;
    dList0.push_back(1);
    dList0.push_back(2);
    dList0.push_back(3);
    dList0.push_back(4);
    dList0.push_back(5);
    DoubleList dList2(dList0);
    cout << "List0: " << dList0 << endl;
    cout << "Decl and Init of List2 with List0" << endl;
    cout << "Front of List0: " << dList0.front() << endl;
    cout << "Back of List0: " <<dList0.back() << endl;
    cout << "========================================" << endl;
    DoubleList dList1;
    dList1.push_front(1);
    dList1.push_front(2);
    dList1.push_front(3);
    dList1.push_front(4);
    dList1.push_front(5);
    cout << "List1: " << dList1 << endl;
    cout << "Front of List1: " << dList1.front() << endl;
    cout << "Back of List1: " << dList1.back() << endl;
    cout << "========================================" << endl;
    cout << "List0: " << dList0 << endl;
    dList0.pop_front();
    cout << "List0: " << dList0 << endl;
    dList0.pop_front();
    cout << "List0: " << dList0 << endl;
    dList0.pop_front();
    cout << "List0: " << dList0 << endl;
    dList0.pop_front();
    cout << "List0: " << dList0 << endl;
    dList0.pop_front();
    cout << "List0: " << dList0 << endl;
    //    cout << "Front of List0: " << dList0.front() << endl;
    cout << "========================================" << endl;
    cout << "List1: " << dList1 << endl;
    dList1.pop_back();
    cout << "List1: " << dList1 << endl;
    dList1.pop_back();
    cout << "List1: " << dList1 << endl;
    dList1.pop_back();
    cout << "List1: " << dList1 << endl;
    dList1.pop_back();
    cout << "List1: " << dList1 << endl;
    dList1.pop_back();
    cout << "List1: " << dList1 << endl;
    //    cout << "Back of List1: " << dList1.back() << endl;
    cout << "========================================" << endl;
    cout << "List2; Copy from List0: " << dList2 << endl;
    DoubleList dList3;
    cout << "Decl of List3" << endl;
    dList3.push_back(8);
    dList3.push_back(9);
    dList3.push_back(10);
    dList3.push_back(11);
    cout << "List3: " << dList3 << endl;
    dList3 = dList2;
    cout << "List3; Overwritten by List2: " << dList3 << endl;
    cout << "========================================" << endl;
    DoubleList dList4;
    dList4.push_front(76);
    dList4.push_front(85);
    DoubleList dList5(dList4);
    dList5.push_front(7);
    dList5.push_front(8);
    cout << "List4: " << dList4 << endl;
    cout << "List5: " << dList5 << endl;
    //    cout << "Back of List5: " << dList5.back() << endl;
    //    dList5.pop_back();
    //    cout << "List5: " << dList5 << endl;
    dList5.push_front(4);
    dList5.push_front(5);
    dList5.push_back(4);
    dList5.push_back(5);
    cout << "List5: " << dList5 << endl;
    dList5 = dList4;
    cout << "List5; overwritten by List4: " << dList5 << endl;
    return 0;
}
