/*
 Linked List:
 delete Odd Value
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
    
    void deleteOddVal() {
         ListElem** p = &m_pHead;
         ListElem* pLast = nullptr;
         while(*p) {
             if ((*p)->m_iCont % 2 != 0) {
                 ListElem* tmp = *p;
                 *p = (*p)->m_pNext;
                 delete tmp;
             } else {
                 pLast = *p;
                 p = &(*p)->m_pNext;
             }
         }
         m_pTail = pLast;
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
//    list0.push_back(100);
//    list0.push_back(100);
//    list0.push_back(100);
//    list0.push_back(100);
//    list0.push_back(100);
//    list0.push_back(100);
    list0.push_back(6);
//    list0.push_back(110);
    list0.push_back(100);
    list0.push_back(199);
    list0.push_back(979);
    list0.push_back(100);
//    list0.push_back(100);
    cout << list0 << endl;
    list0.deleteOddVal();
    cout << list0 << endl;
//    cout << list0.front() << endl;
//    cout << list0.back() << endl;
    return 0;
}
