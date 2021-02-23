/*
13.08.2020 - Ruben Allenstein
Aufgabe 2:
Fügen Sie der Implementierung von Vektoren und Listen Exceptions hinzu, wenn mittels des []-Operators oder
 der front(), back(), pop_front() bzw. pop_back() Methoden auf illegale Elemente bzw. leere Vektoren / Listen zugegriffen wird.
 
 Frage:
 anbei haben wir für Vektoren und Listen (DLL und LL) Exceptions implementiert.
 Wir fragen uns, ob dies so richtig ist.
 
 Antwort:
 Bei den beiden Listen testen Sie in den back() Methoden m_pHead,
 dereferenzieren dann aber m_pTail. Schöner wäre es, m_pTail dann auch
 vorher zu testen.
 Das sind aber alles nur Kleinigkeiten.
*/


#include <iostream>
using namespace std;

class MyException: public exception {
  virtual const char* what() const throw() {
    return "List is empty!";
  }
};

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
        copy_Constructor(dl);
    }
    ~DoubleList() {
        destructor();
    }
    DoubleList &operator=(const DoubleList &dl) {
        if(this == &dl) {
            return *this;
        }
        destructor();
        copy_Constructor(dl);
        return *this;
    }
    friend ostream& operator<<(ostream& os, const DoubleList& crArg) {
        if (crArg.m_pHead)
            os << *crArg.m_pHead;
        return os;
    }
    void copy_Constructor(const DoubleList &dl) {
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
        if(!m_pTail)
            m_pTail = m_pHead;
    }
    void push_back(unsigned i) {
        m_pTail = new ListElem(i, nullptr, m_pTail);
        if(!m_pHead)
            m_pHead = m_pTail;
    }
    void pop_back() {
        if(!m_pHead)
            throw MyException();
        ListElem *p = m_pTail;
        m_pTail = m_pTail->m_pPrev;
        delete p;
        if (m_pTail)
            m_pTail->m_pNext = nullptr;
        else
            m_pHead = nullptr;
    }
    void pop_front() {
        if(!m_pTail)
            throw MyException();
        ListElem *p = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete p;
        if (m_pHead)
            m_pHead->m_pPrev = nullptr;
        else
            m_pTail = nullptr;
    }
    unsigned front() {
        if(!m_pHead) {
            throw MyException();
        } else {
            return m_pHead->m_iElem;
        }
    }
    unsigned back() {
        if(!m_pHead) {
            throw MyException();
        } else {
            return m_pTail->m_iElem;
        }
    }
};

int main() {
    DoubleList dList1;
    dList1.push_back(0);
    dList1.push_back(1);
    dList1.push_back(2);
    dList1.push_back(3);
    dList1.push_back(4);
    dList1.push_back(5);
    cout << dList1 << endl;
    dList1.pop_back();
    dList1.pop_back();
    dList1.pop_back();
    dList1.pop_back();
    dList1.pop_back();
    dList1.pop_back();
    cout << dList1.back() << endl;
    cout << dList1 << endl;
    return 0;
}
