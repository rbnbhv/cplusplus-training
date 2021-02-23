#include <iostream> //iteratoren fehlen!
using namespace std;

class DoubleList {
    struct ListElem {
        int m_i;
        ListElem *m_pNext = nullptr;
        ListElem *m_pPrev = nullptr;
        
        ListElem(int i, ListElem *next, ListElem *prev) : m_i(i), m_pNext(next), m_pPrev(prev) {
            if (m_pNext) {
                m_pNext->m_pPrev = this;
            }
            if (m_pPrev) {
                m_pPrev->m_pNext = this;
            }
        }
        
        friend ostream& operator << (ostream& os, const ListElem crArg) {
            os << crArg.m_i << " ";
            if (crArg.m_pNext) {
                os << *crArg.m_pNext;
            }
            return os;
        }
    };
    
private:
    ListElem* m_pHead = nullptr;
    ListElem* m_pTail = nullptr;
    
public:
    DoubleList() {
    }
    
    DoubleList(const DoubleList& dl) {
        copyHelper(dl);
    }
    
    ~DoubleList() {
        destroy();
    }
    
    DoubleList& operator=(const DoubleList& dl) {
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
    
    friend ostream& operator<< (ostream& os, const DoubleList& dl) {
        if (dl.m_pHead) {
            os << *dl.m_pHead;
        }
        return os;
    }
    
    void push_front(int elem) {
        m_pHead = new ListElem(elem, m_pHead, nullptr);
        if (!m_pTail) {
            m_pTail = m_pHead;
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
    
    void pop_back() {
        ListElem *p = m_pTail;
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
    }1
    
    int findSecMax() {
         int first = m_pHead->m_i;
         int second = m_pHead->m_pNext->m_i;
         if(second > first) {
             int tmp = first;
             first = second;
             second = tmp;
         }
         ListElem* p = m_pHead->m_pNext->m_pNext;
         while(p) {
             if(p->m_i > first) {
                 second = first;
                 first = p->m_i;
             }
             else if(p->m_i > second) {
                 second = p->m_i;
             }
             p = p->m_pNext;
         }
         return second;
     }
    
    void deleteOddVal() {
         ListElem* p = m_pHead;
         while(p) {
             ListElem* tmp = p;
             p = p->m_pNext;
             if(tmp->m_i % 2 != 0) {
                 if(tmp == m_pHead) {
                     m_pHead = tmp->m_pNext;
                 }
                 if(tmp->m_pNext){
                     tmp->m_pNext->m_pPrev = tmp->m_pPrev;
                 }
                 if(tmp->m_pPrev) {
                     tmp->m_pPrev->m_pNext = tmp->m_pNext;
                 }
                 if(tmp == m_pTail) {
                     m_pTail = tmp->m_pPrev;
                 }
                 delete tmp;
             }
         }
     }
    
    void deleteIdx(int index) {
        ListElem* tmp = m_pHead;
        for(int i = 0; i < index; ++i) {
            tmp = tmp->m_pNext;
        }
        if(tmp->m_pPrev) {
            tmp->m_pPrev->m_pNext = tmp->m_pNext;
        } else {
            m_pHead = tmp->m_pNext;
        }
        if(tmp->m_pNext) {
            tmp->m_pNext->m_pPrev = tmp->m_pPrev;
        } else {
            m_pTail = tmp->m_pPrev;
        }
        delete tmp;
    }
    
    void deleteMatch(int i) {
        ListElem* p = m_pHead;
        while(p) {
            ListElem* tmp = p;
            p = p->m_pNext;
            if(tmp->m_i == i) {
                if(tmp == m_pHead) {
                    m_pHead = tmp->m_pNext;
                }
                if(tmp->m_pNext){
                    tmp->m_pNext->m_pPrev = tmp->m_pPrev;
                }
                if(tmp->m_pPrev) {
                    tmp->m_pPrev->m_pNext = tmp->m_pNext;
                }
                if(tmp == m_pTail) {
                    m_pTail = tmp->m_pPrev;
                }
                delete tmp;
                tmp = nullptr;
            }
        }
    }
    
};

int main() {
    DoubleList db;
    db.push_back(2);
    db.push_front(3);
    cout << db << endl;
    cout << db.front() << " MOIN" << endl;
    cout << db.back() << " MOIN" << endl;
}
