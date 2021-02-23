#include <iostream>
using namespace std;

class T {
    struct L {
        int m_iKey;
        L *m_pLeft = 0;
        L *m_pRight = 0;
    
    };
private:
    L *m_Root = nullptr;
    
    
public:
    T() {
    }
    
    T(const T& bt) {
        m_Root = copyTree(bt.m_Root);
    }
    
    ~T() {
        destroyRec(m_Root);
    }
    
    void destroyRec(L *node) {
        if (node) {
            destroyRec(node->m_pLeft);
            destroyRec(node->m_pRight);
            delete node;
        }
    }
    
    L* copyTree(L *node) {
        if (!node) {
            return nullptr;
        }
        L *copyRoot = new L;
        copyRoot->m_pLeft = copyTree(copyRoot->m_pLeft);
        copyRoot->m_pRight = copyTree(copyRoot->m_pRight);
        return copyRoot;
    }
    
};
