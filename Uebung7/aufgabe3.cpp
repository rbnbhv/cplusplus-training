/*
30.07.2020 - Ruben Allenstein
Aufgabe 3 - Binärbaum:
Implementieren Sie für den binären Suchbaum über unsigned int eine rekursive Suchmethode und eine Methode, die die Anzahl
der Knoten zurückliefert.

 Frage:
 anbei ein anderer Ansatz, da wir das Gefühl haben auf dem Holzweg zu sein.
 CopyTree ist nun eine Methode mit einem Rückgabetyp (Node*).
 Wir kopieren unserer Meinung nach nun tatsächlich und beheben, dass von Ihnen zuvor geschilderte Problem.

 Antwort:
 so sieht es gut aus. Die Methoden copyTree und destroyRecursive könnten
 auch Klassenmethoden sein, da sie nicht auf m_pRoot zugreifen. Viele Grüße
 */

#include <iostream>
#include <string>

using namespace std;

class BinTree {

private:

    struct Node {

        unsigned m_iKey;
        string m_Data;
        Node* m_pLeft = nullptr;
        Node* m_pRight = nullptr;

        Node(unsigned iKey, const string& crData) : m_iKey(iKey), m_Data(crData) {

        }
    };

private:

    Node* m_pRoot = nullptr;

public:

    BinTree() {

    }

    BinTree(const BinTree &bt) {
        m_pRoot = copyTree(bt.m_pRoot);
    }

    ~BinTree() {
        destroyRecursive(m_pRoot);
    }

    BinTree &operator=(const BinTree &bt) {
        if(this == &bt) {
            return *this;
        }
        destroyRecursive(m_pRoot);
        m_pRoot = copyTree(bt.m_pRoot);
        return *this;
    }

    Node* copyTree(Node* node) {
        if(!node)
            return nullptr;
        Node* copyRoot = new Node(node->m_iKey, node->m_Data);
        copyRoot->m_pLeft = copyTree(node->m_pLeft);
        copyRoot->m_pRight = copyTree(node->m_pRight);
        return copyRoot;
    }

    void destroyRecursive(Node* node) {
        if(node) {
            destroyRecursive(node->m_pLeft);
            destroyRecursive(node->m_pRight);
            delete node;
        }
    }

    string* iterSearch(unsigned iKey) {
        Node* pTmp = m_pRoot;
        while(pTmp) {
            if(iKey == pTmp->m_iKey)
                return &pTmp->m_Data;
            pTmp = (iKey < pTmp->m_iKey) ? pTmp->m_pLeft : pTmp->m_pRight;
        }
        return nullptr;
    }

    string* recSearch(unsigned iKey) {
        return recSearch(m_pRoot, iKey);
    }

    string* recSearch(Node* pTmp, unsigned iKey) {
        if(!pTmp)
            return nullptr;
        if(iKey == pTmp->m_iKey)
            return &pTmp->m_Data;
        return iKey < pTmp->m_iKey ? recSearch(pTmp->m_pLeft, iKey) : recSearch(pTmp->m_pRight, iKey);
    }

    unsigned recCount() {
        return recCount(m_pRoot);
    }

    unsigned recCount(Node* p) {
        unsigned x;
        unsigned y;
        if(p) {
            x = recCount(p->m_pLeft);
            y = recCount(p->m_pRight);
//            cout << x << " " << y << endl;
            return x+y+1;
        }
        return 0;
    }

    bool insert2(unsigned iKey,const string& crData) {
        Node* pTmp = m_pRoot;
        Node* pFather = nullptr;
        while (pTmp) {
            pFather = pTmp;
            if (iKey < pTmp->m_iKey)
                pTmp = pTmp->m_pLeft;
            else if (pTmp->m_iKey < iKey)
                pTmp = pTmp->m_pRight;
            else
                return false;
        }
        pTmp = new Node(iKey,crData);
        if (pFather == nullptr)
            m_pRoot = pTmp;
        else if (iKey < pFather->m_iKey)
            pFather->m_pLeft = pTmp;
        else
            pFather->m_pRight = pTmp;
        return true;
    }

    void printTree(ostream& os, Node* node) {
        if(!node)
            return;
        cout << node->m_Data << ":  ";
        if(node->m_pLeft)
            cout << "Left: " << node->m_pLeft->m_Data << "; ";
        if(node->m_pRight)
            cout << "Right: " << node->m_pRight->m_Data << "; ";
        cout << endl;
        printTree(os, node->m_pLeft);
        printTree(os, node->m_pRight);
    }

     friend ostream& operator<<(ostream &os, BinTree& bt) {
        if(bt.m_pRoot)
            bt.printTree(os, bt.m_pRoot);
        return os;
    }
};


int main() {
    BinTree bTree;
    cout << bTree.insert2(10, "10") << endl;
    cout << bTree.insert2(200, "200") << endl;
    cout << bTree.insert2(30, "30") << endl;
    cout << bTree.insert2(44, "44") << endl;
    cout << bTree.insert2(5, "5") << endl;
    cout << endl;
    cout << "BT: " << endl << bTree << endl;
    cout << endl;
    cout << bTree.iterSearch(30);
    cout << endl;
    cout << bTree.recSearch(30);
    cout << endl << endl;
    BinTree bTree2;
    cout << endl;
    cout << bTree2.insert2(4, "4") << endl;
    cout << bTree2.insert2(56, "56") << endl;
    cout << "BT2: " << endl << bTree2 << endl;
    cout << "Number of nodes; BT2: " << bTree2.recCount() << endl;
    cout << endl << endl;
    bTree2 = bTree;
    cout << bTree.insert2(6, "6") << endl;
    cout << "BT: " << endl << bTree << endl << endl;
    cout << "BT2: " << endl << bTree2 << endl;
    BinTree bTree3(bTree);
    cout << "BT3: " << endl << bTree3 << endl;
    cout << "Number of nodes; BT3: " << bTree3.recCount() << endl;
    return 0;
}
