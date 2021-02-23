/*
 Double Linked List:
 delete Odd Value
*/


#include <iostream>
using namespace std;

class L {
    struct E {
        E(unsigned i, E* pN, E* pP) : m_i(i),m_N(pN),m_P(pP) {
            if (m_N)
                m_N->m_P = this;
            if (m_P)
                m_P->m_N = this;
        }
        friend ostream& operator<<(ostream& os,const E& crArg) {
            os << crArg.m_i << " ";
            if (crArg.m_N)
                os << *crArg.m_N;
            return os;
        }
        int m_i;
        E* m_N = nullptr;
        E* m_P = nullptr;
    };
public:
    friend ostream& operator<<(ostream& os, const L& crArg) {
        if (crArg.m_Head)
            os << *crArg.m_Head;
        return os;
    }
    void deleteOddVal() {
        E* p = m_Head;
        while(p) {
            E* tmp = p;
            p = p->m_N;
            if(tmp->m_i % 2 != 0) {
                if(tmp == m_Head) {
                    m_Head = tmp->m_N;
                }
                if(tmp->m_N){
                    tmp->m_N->m_P = tmp->m_P;
                }
                if(tmp->m_P) {
                    tmp->m_P->m_N = tmp->m_N;
                }
                if(tmp == m_Tail) {
                    m_Tail = tmp->m_P;
                }
                delete tmp;
            }
        }
    }
    void push_front(int i) {
        m_Head = new E(i, m_Head, nullptr);
        if(!m_Tail)
            m_Tail = m_Head;
    }

private:

    E* m_Head = nullptr;
    E* m_Tail = nullptr;

};

int main() {
    L doubleList;
    doubleList.push_front(3);
    doubleList.push_front(8);
    doubleList.push_front(8);
    doubleList.push_front(6);
    doubleList.push_front(7);
    doubleList.push_front(8);
    doubleList.push_front(4);
    doubleList.push_front(9);
    cout << doubleList << endl;
    doubleList.deleteOddVal();
    cout << doubleList << endl;
    return 0;
}
