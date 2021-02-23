#include <iostream>
using namespace std;

class LinkedList {
    struct ListElem {
        int m_i;
        ListElem *m_pNext = nullptr;
        
        ListElem(int i, ListElem *next) : m_i(i), m_pNext(next) {
        
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
    LinkedList() {
    }
    
    LinkedList(const LinkedList& l) {
        copyHelper(l);
    }
    
    ~LinkedList() {
        destroy();
    }
    
    void copyHelper(const LinkedList& l) {
        ListElem *p = m_pHead;
        while (p) {
            this->push_back = (p->m_i);
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
    
    LinkedList& operator =(const LinkedList& l) {
        if(this == &l) {
            return *this;
        }
        destroy();
        copyHelper(l);
        return *this;
    }
    
    void push_front(int elem) {
        m_pHead = new ListElem(elem, m_pHead)
    }
    
};
