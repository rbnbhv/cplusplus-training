/* Review: 09.08.2020
Aufgabe 1: deleteEverySecond Vektoren
Nicht sortierter Binärbaum. Alle Blätter des Baumes sollen gelöscht werden. (void deleteLeafs())
Kelb Review:
- deleteLeafs ist richtig
*/

#include <iostream>
using namespace std;

class T {
    struct L {

        L(int i) : m_c(i) {

        }
        int m_c;
        L* m_Left = nullptr;
        L* m_Right = nullptr;
    };

private:
    L* m_Root = nullptr;

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
    void deleteLeafs() {
        m_Root = deleteLeafs(m_Root);
    }
    L* deleteLeafs(L* node) {
        if(!node) {
            return nullptr;
        }
        if(!node->m_Left && !node->m_Right) {
            delete node;
            return nullptr;
        }
        node->m_Left = deleteLeafs(node->m_Left);
        node->m_Right = deleteLeafs(node->m_Right);
        return node;
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
    tree.deleteLeafs();
    cout << tree << endl;
    return 0;
}
