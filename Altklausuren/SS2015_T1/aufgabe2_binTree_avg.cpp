/* Review: 08.08.2020
Aufgabe 1: Binärbaum
Implementieren Sie eine Objektmethode float avg(), die zu einem Binärbaum den Durchschnitt der Knoteninhalte berechnet.

 Kelb Review:
- ja, das habe ich mir so vorgestellt, aber die Methoden sum und count
können um die beiden Parameter x und y erleichtert werden. Die Werte,
die Sie da in die Rekursion hinab geben, werden nie gebraucht. Also
müssen Sie sie auch gar nicht hinab reichen. Es werden nur Werte in der
Rekursion nach oben gegeben.

Der Rückgabewert von sum sollte int nicht float sein. Die Konvertierung
nach float findet dann in avg statt.
 
 Antwort:
- danke, wir konnten nun bzgl. Kompaktheit einiges gut machen, anbei die Überarbeitung.

 */

#include <iostream>
using namespace std;

class T {
    struct L {
        L(int i) : m_c(i) {

        }

        unsigned m_c;
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
    int countNodes() {
        return countNodes(m_Root);
    }
    int countNodes(L* node) {
        return !node ? 0 : countNodes(node->m_Left) + countNodes(node->m_Right) + 1;
    }
    int sum() {
        return sum(m_Root);
    }
    int sum(L* node) {
        return !node ? 0 : sum(node->m_Left) + sum(node->m_Right) + node->m_c;
    }
    float avg() {
        return (float)sum() / countNodes();
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
        pTmp = new L(iKey);
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
    tree.insert2(15);
    tree.insert2(5);
    tree.insert2(7);
    tree.insert2(2);
    tree.insert2(9);
    tree.insert2(6);
    cout << tree << endl;
    cout << tree.countNodes() << endl;
    cout << tree.sum() << endl;
    cout << tree.avg() << endl;
    return 0;
}
