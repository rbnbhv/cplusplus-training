/* Review: 02.08.2020
Binärbaum:
- Implementieren Sie Konstruktor, Copy-Konstruktor und Destruktor

Kelb Review:
- sieht gut aus
*/


#include <iostream>
using namespace std;

class T {
    struct L {

        unsigned m_c;
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
    L* copyHelper(L* node) {
        if(!node) {
            return nullptr;
        }
        L *copyRoot = new L;
        copyRoot->m_c = node->m_c;
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

    void deleteSingle(){
        m_Root = deleteSingle(m_Root);
    }
    L* deleteSingle(L* p) {
        if(!p) {
            return nullptr;
        }
        p->m_Left = deleteSingle(p->m_Left);
        p->m_Right = deleteSingle(p->m_Right);
        if((!p->m_Left && p->m_Right) || (p->m_Left && !p->m_Right)) {
            L* child = p->m_Left ? p->m_Left : p->m_Right;
            delete p;
            return child;
        }
        return p;
    }
    bool insert2(unsigned iKey) {
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
        pTmp = new L;
        pTmp->m_c = iKey;
        if (pFather == nullptr)
            m_Root = pTmp;
        else if (iKey < pFather->m_c)
            pFather->m_Left = pTmp;
        else
            pFather->m_Right = pTmp;
        return true;
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
    cout << tree << endl;
    T tree2(tree);
    cout << tree2 << endl;
    tree2.deleteSingle();
    cout << tree2 << endl;
    return 0;
}
