/* Review: 06.08.2020

Kelb Review:
- so passt es
*/

#include <iostream>
using namespace std;

class T {
    struct L {

        L(int i) : m_c(i) {

        }
        int m_c;
        L* m_Left = 0;
        L* m_Right = 0;
    };

private:
    L* m_Root = 0;

public:
    //Konstruktor
    T() {

    }
    //Copykonstruktor
    T(const T &t) {
        m_Root = copyHelper(t.m_Root);
    }
    //Destruktor
    ~T() {
        destroyRecursive(m_Root);
    }
    T &operator=(const T &t) {
        if(this == &t) {
            return *this;
        }
        destroyRecursive(m_Root);
        m_Root = copyHelper(t.m_Root);
        return *this;
    }
    L* copyHelper(L* node) {
        if(!node) {
            return nullptr;
        }
        L *copyRoot = new L(node->m_c);
        copyRoot->m_Left = copyHelper(node->m_Left);
        copyRoot->m_Right = copyHelper(node->m_Right);
        return copyRoot;
    }
    void destroyRecursive(L* node) {
        if(node) {
            destroyRecursive(node->m_Left);
            destroyRecursive(node->m_Right);
            delete node;
        }
    }
    bool insert2(int iKey) {
        L* pTmp = m_Root;
        L* pFather = nullptr;
        while (pTmp) {
            pFather = pTmp;
            if (iKey < pTmp->m_c)
                pTmp = pTmp->m_Left;
            else if (pTmp->m_c < iKey)
                pTmp = pTmp->m_Right;
            else
                return false;
        }
        pTmp = new L(iKey);
        if (pFather == nullptr)
            m_Root = pTmp;
        else if (iKey < pFather->m_c)
            pFather->m_Left = pTmp;
        else
            pFather->m_Right = pTmp;
        return true;
    }
    int secondLeast() {
        return secondLeast(m_Root);
    }
    int secondLeast(L* node) {
        L* parent = nullptr;
        L* child = node;
        while(child->m_Left) {
            parent = child;
            child = child->m_Left;
        }
        if(!child->m_Right) {
            return parent->m_c;
        }
        child = child->m_Right;
        while(child->m_Left)
            child = child->m_Left;
        return child->m_c;
    }
    
    void printTree(ostream& os, L* node) {
        if(!node)
            return;
        cout << node->m_c << ":  ";
        if(node->m_Left)
            cout << "Left: " << node->m_Left->m_c<< "; ";
        if(node->m_Right)
            cout << "Right: " << node->m_Right->m_c << "; ";
        cout << endl;
        printTree(os, node->m_Left);
        printTree(os, node->m_Right);
    }

     friend ostream& operator<<(ostream &os, T& bt) {
        if(bt.m_Root)
            bt.printTree(os, bt.m_Root);
        return os;
    }
};

int main() {
    T tree;
    tree.insert2(3);
    tree.insert2(8);
    tree.insert2(13);
    tree.insert2(5);
    tree.insert2(7);
    tree.insert2(2);
    tree.insert2(9);
    tree.insert2(6);
    tree.insert2(1);
    tree.insert2(44);
    cout << tree << endl;
    cout << tree.secondLeast() << endl;
    return 0;
}
