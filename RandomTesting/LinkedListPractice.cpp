#include <iostream>
using namespace std;

class LinkedList {
    struct ListElem {
        int m_i;
        ListElem *m_pNext = nullptr;
        ListElem(int i, ListElem *next) : m_i(i), m_pNext(next) {
        }
        friend ostream& operator << (ostream& os, const ListElem crArg) {
            os << crArg.m_i << " " ;
            if(crArg.m_pNext) {
                os << *crArg.m_pNext;
            }
            return os;
        }
    };
private:
    ListElem *m_pHead = nullptr;
    ListElem *m_Tail = nullptr;
    
public:
    LinkedList() {
    }
    
    LinkedList(const LinkedList& l) {
        copyHelper(l);
    }
    
    ~LinkedList() {
        destroy();
    }
    
    LinkedList& operator =(const LinkedList& l) {
        if (this == &l) {
            return *this;
        }
        destroy();
        copyHelper(l);
        return *this;
    }
    
    void copyHelper(const LinkedList& l) {
        ListElem *p = l.m_pHead;
        while (p) {
            this->push_back(p->m_i);
            p = p->m_pNext;
        }
    }
    
    void destroy() {
        ListElem *p = nullptr;
        while(m_pHead) {
            p = m_pHead->m_pNext;
            delete m_pHead;
            m_pHead =p;
        }
        m_pTail = nullptr;
    }
    
    void push_front(int elem) {
        m_pHead = new ListElem(elem, m_pHead);
        if (!m_pTail) {
            m_pTail = m_pHead
        }
    }
    
    void push_back(int elem) {
        ListElem *node = new ListElem(elem, nullptr);
        if (!m_pHead) {
            m_pHead = m_pTail = node;
        }
        else {
            m_pTail->m_pNext = node;
            m_pTail = m_pTail->m_pNext;
        }
    }
    
    void pop_front() {
        if (m_pHead == m_pTail) {
            delete m_pHead;
            m_pHead = m_pTail = nullptr;
        }
        else {
            ListElem *p = m_pHead;
            m_pHead = m_pHead->m_pNext;
            delete p;
        }
    }
    
    void pop_back() {
        if (m_pTail == m_Head) {
            delete m_pHead;
            m_pHead = m_pTail = nullptr;
        }
        else {
            ListElem *p = m_pHead;
            while (p->m_pNext != m_pTail) {
                p = p->m_pNext;
            }
            delete m_pTail;
            m_pTail = p;
            m_pTail->m_pNext = nullptr;
        }
    }
    
    int front() {
        return m_pHead->m_i;
    }
    
    int back() {
        return m_pTail->m_i;
    }
    
    friend ostream& operator <<(ostream& os, const LinkedList& l) {
        if (l.m_pHead) {
            os << *l.m_pHead;
        }
        return os;
    }
};

int main() {
    
    
}
