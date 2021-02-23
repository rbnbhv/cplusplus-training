/* Review: 04.08.2020
BinTree
 - Implementieren Sie eine Methode printSuMpath, die an allen Blättern des Baums Die Summe der int-Werte ausgibt, die auf dem Weg
 von der Wurzel zum Blatt liegen.

 Bedeutet:
 --> Sie sollten an jedem Blatt des Baumes einen Wert ausgeben. Dieser sollte die Summe aller Werte der Knoten bis zu diesem Blatt beinhalten. Ein Blatt hat keine Kinder. Deshalb ist es ja ein Blatt. Sie müssen beim Absteigen die bisherige Summe hinunter reichen und jeweils den aktuellen int Wert hinzuaddieren und weiter nach unten reichen. Am Blatt geben Sie dann den Wert aus.
 
Kelb Review:
- so passt es
*/

#include <iostream>
using namespace std;

class BinTree {

private:

    struct Node {

        int m_iKey;
        Node* m_pLeft = nullptr;
        Node* m_pRight = nullptr;

        Node(int iKey) : m_iKey(iKey) {

        }
    };

public:
    void printSumPath() {
        printSumPath(m_pRoot, 0);
    }
    void printSumPath(Node* p, int sum) {
        if (p){
            sum += p->m_iKey;
            printSumPath(p->m_pLeft, sum);
            printSumPath(p->m_pRight, sum);
            if (!p->m_pLeft && !p->m_pRight){
                cout << p->m_iKey << " (Leaf); SumPath: " << sum << "    ";
            }
        }
    }
    bool insert2(int iKey) {
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
        pTmp = new Node(iKey);
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
        cout << node->m_iKey << ":  ";
        if(node->m_pLeft)
            cout << "Left: " << node->m_pLeft->m_iKey << "; ";
        if(node->m_pRight)
            cout << "Right: " << node->m_pRight->m_iKey << "; ";
        cout << endl;
        printTree(os, node->m_pLeft);
        printTree(os, node->m_pRight);
    }

     friend ostream& operator<<(ostream &os, BinTree& bt) {
        if(bt.m_pRoot)
            bt.printTree(os, bt.m_pRoot);
        return os;
    }
private:

    Node* m_pRoot = nullptr;
};

int main(){
    BinTree bTree;
    cout << bTree.insert2(10) << endl;
    cout << bTree.insert2(5) << endl;
    cout << bTree.insert2(8) << endl;
    cout << bTree.insert2(3) << endl;
    cout << bTree.insert2(4) << endl;
    cout << bTree.insert2(1) << endl;
    cout << bTree.insert2(7) << endl;
    cout << bTree.insert2(18) << endl;
    cout << bTree.insert2(9) << endl;
    cout << bTree << endl;
    bTree.printSumPath();
    return 0;
}
