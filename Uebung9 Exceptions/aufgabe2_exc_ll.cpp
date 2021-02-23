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
    void pop_front() {
        if(!m_pHead) {
            throw MyException();
        } else if (m_pHead == m_pTail) {
             delete m_pHead;
             m_pHead = m_pTail = nullptr;
        } else {
            ListElem *p = m_pHead;
            m_pHead = m_pHead->m_pNext;
            delete p;
        }
    }
    void pop_back() {
        if(!m_pHead) {
            throw MyException();
        } else if (m_pHead == m_pTail) {
             delete m_pHead;
             m_pHead = m_pTail = nullptr;
        } else {
            ListElem* p = m_pHead;
            while (p->m_pNext != m_pTail)
                p = p->m_pNext;
            delete m_pTail;
            m_pTail = p;
            m_pTail->m_pNext = nullptr;
        }
    }
    int front() {
        if(!m_pHead) {
            throw MyException();
        } else {
            return m_pHead->m_iCont;
        }
    }
    int back() {
        if(!m_pHead) {
            throw MyException();
        } else {
            return m_pTail->m_iCont;
        }
    }
};

int main() {
    LinkedList list1;
    list1.push_back(0);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(5);
    cout << list1 << endl;
    list1.pop_front();
    list1.pop_front();
    list1.pop_front();
    list1.pop_front();
    list1.pop_front();
    list1.pop_front();
    cout << list1.back() << endl;
    cout << list1 << endl;
    return 0;
}
