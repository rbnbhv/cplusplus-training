#include <iostream>
using namespace std;

class DoubleList {
    struct ListElem {
        int m_i;
        ListElem *m_pNext = nullptr;
        ListElem *m_pPrev = nullptr;
        
        ListElem(int i, ListElem *next, ListElem *prev) : m_i(i), m_pNext(next), m_pPrev(prev) {
            if (m_pPrev) {
                m_pPrev->m_pNext = this;
            }
            if (m_pNext) {
                m_pNext->m_pPrev = this;
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
    ListElem *m_pTail = nullptr;
    ListElem *m_pHead = nullptr;
    
public:
    DoubleList() {
    }
    
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
            m_pTail = m_pHead;
        }
    }
    
    void push_back(int elem) {
        ListElem *node = new ListElem(elem, nullptr, m_pTail);
        if (!m_pHead) {
            m_pHead = m_pTail;
        }
    }
    
    void pop_front() {
        ListElem* p = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete p;
        if (m_pHead) {
            m_pHead->m_pPrev = nullptr;
        }
        else {
            m_pTail = nullptr;
        }
    }
    
    void pop_back() {
        ListElem* p = m_pTail;
        m_pTail = m_pTail->m_pPrev;
        delete p;
        if (m_pTail) {
            m_pTail->m_pNext = nullptr;
        }
        else {
            m_pHead = nullptr;
        }
    }
    
    int front() {
        return m_pHead->m_i;
    }
    
    int back() {
        return m_pTail->m_i;
    }
    
    friend ostream& operator <<(ostream& os, const DoubleList& dl) {
        if (dl.m_pHead) {
            os << *dl.m_pHead;
        }
        return os;
    }
    
};
