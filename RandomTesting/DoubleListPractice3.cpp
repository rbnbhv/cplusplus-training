#include <iostream>
using namespace std;

class DoubleList {
    struct ListElem {
        int m_i;
        ListElem *m_pNext = nullptr;
        ListElem *m_pPrev = nullptr;
        ListElem(int i, ListElem *next, ListElem *prev) : m_i(i), m_pPrev(prev), m_pNext(next) {
            if (m_pNext) {
                m_pNext->m_pPrev = this;
            }
            if (m_pPrev) {
                m_pPrev->m_pNext = this;
            }
        }
        friend ostream& operator <<(ostream& os, const ListElem& crArg) {
            os << crArg.m_i << " ";
            if (crArg.m_pNext) {
                os << *crArg.m_pNext;
            }
            return os;
        }
    };
    
private:
    ListElem *m_pHead = nullptr;
    ListElem *m_pTail = nullptr;
    
public:
    DoubleList() {}
    DoubleList(const DoubleList& dl) {
        copyHelper(dl);
    }
    ~DoubleList() {
        destroy();
    }
    
    DoubleList& operator =(const DoubleList& dl) {
        if (this == &dl) {
            return *this;
        }
        destroy();
        copyHelper(dl);
        return *this;
    }
    
    void copyHelper(const DoubleList& dl) {
        ListElem *p = dl.m_pHead;
        while (p) {
            this->push_back(p->m_i);
            p = p->m_pNext;
        }
    }
    
    void destroy() {
        ListElem *p = nullptr;
        while (m_pHead) {
            p = m_pHead->m_pNext;
            delete m_pHead;
            m_pHead = p;
        }
        m_pTail = nullptr;
    }
    
    void push_front(int elem) {
        m_pHead = new ListElem(elem, m_pHead, nullptr);
        if (!m_pTail) {
            m_pHead = m_pTail;
        }
    }
    
    void push_back(int elem) {
        m_pTail = new ListElem(elem, nullptr, m_pTail);
        if (!m_pHead) {
            m_pHead = m_pTail;
        }
    }
    
    void pop_front() {
        ListElem *p = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete p;
        if (m_pHead) {
            m_pHead->m_pPrev = nullptr;
        }
        else {
            m_pTail = nullptr;
        }
    }
    
    int front() {
        return m_pHead->m_i;
    }
    
    int back() {
        return m_pTail->m_i;
    }
    
    friend ostream& operator << (ostream& os, const DoubleList& dl) {
        if (dl.m_pHead) {
            os << *dl.m_pHead;
        }
        return os;
    }
};
