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
    void invert() {
        E* p1 = m_Head;
        E* p2 = m_Tail;
        while(p1 != p2 && p1->m_P != p2) {
            int tmp = p1->m_i;
            p1->m_i = p2->m_i;
            p2->m_i = tmp;

            p1 = p1->m_N;
            p2 = p2->m_P;
        }
    }
    
    int findSecMax() {
        int first = m_Head->m_i;
        int second = m_Head->m_N->m_i;
        if(second > first) {
            int tmp = first;
            first = second;
            second = tmp;
        }
        E* p = m_Head->m_N->m_N;
        while(p) {
            if(p->m_i > first) {
                second = first;
                first = p->m_i;
            } else if(p->m_i > second) {
                second = p->m_i;
            }
            p = p->m_N;
        }
        return second;
    }
    void push_back(int i) {
        m_Tail = new E(i, nullptr, m_Tail);
        if(!m_Head)
            m_Head = m_Tail;
    }
    int front() {
        return m_Head->m_i;
    }
    int back() {
        return m_Tail->m_i;
    }

private:

    E* m_Head = nullptr;
    E* m_Tail = nullptr;

};

int main() {
    L doubleList;
    doubleList.push_back(19);
    doubleList.push_back(18);
    doubleList.push_back(8);
    doubleList.push_back(6);
    doubleList.push_back(17);
    doubleList.push_back(19);
    doubleList.push_back(17);
    doubleList.push_back(7);
    cout << doubleList << endl;
    doubleList.invert();
    cout << doubleList << endl;
    cout << doubleList.front() << endl;
    cout << doubleList.back() << endl;
    cout << doubleList.findSecMax() << endl;
    return 0;
}
