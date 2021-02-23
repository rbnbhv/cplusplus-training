#include <iostream>
using namespace std;

class BinTree {
    struct Node {
        int m_iKey;
        string m_data;
        Node *m_pLeft = nullptr;
        Node *m_pRight = nullptr;
        
        
        Node(int ikey, const string& crData) : m_iKey(ikey), m_data(crData) {
        }
    };
    
private:
    Node *m_pRoot = nullptr;
    
public:
    BinTree() {
    }
    
    BinTree(const BinTree& bt) {
        m_pRoot = copyHelper(bt.m_pRoot);
    }
    
    ~BinTree() {
        destroyRec(m_pRoot);
    }
    
    BinTree& operator = (const BinTree& bt) {
        if (this == &bt) {
            return *this;
        }
        destroyRec(m_pRoot);
        m_pRoot = copyHelper(bt.m_pRoot);
        return *this;
    }
    
    Node* copyHelper(Node *node) {
        if (!node) {
            return nullptr;
        }
        Node *copyRoot = new Node(node->m_iKey, node->m_data);
        copyRoot->m_pLeft = copyHelper(node->m_pLeft);
        copyRoot->m_pRight = copyHelper(node->m_pRight);
        return copyRoot;
    }
    
    void destroyRec(Node *node) {
        if (node) {
            destroyRec(node->m_pLeft);
            destroyRec(node->m_pRight);
            delete node;
        }
    }
    
    string* searchIter(int iKey) {
        Node *p_Tmp = m_pRoot;
        while (p_Tmp) {
            if (p_Tmp->m_iKey == iKey) {
                return &p_Tmp->m_data;
            }
            p_Tmp = (p_Tmp->m_iKey > iKey) ? p_Tmp->m_pLeft : p_Tmp->m_pRight;
        }
        return nullptr;
    }
    
    string *recSearch(int iKey) {
        return recSearch(m_pRoot, iKey);
    }
    
    string *recSearch(Node *p_Tmp, int iKey) {
        if (iKey == p_Tmp->m_iKey) {
            return &p_Tmp->m_data;
        }
        else if(iKey < p_Tmp->m_iKey) {
            return recSearch(p_Tmp->m_pLeft, iKey);
        }
        else if(iKey > p_Tmp->m_iKey) {
            return recSearch(p_Tmp->m_pRight, iKey);
        }
        else {
            return nullptr;
        }
    }
    
    void deleteLeafs() {
        m_pRoot = deleteLeafs(m_pRoot);
    }
    
    Node* deleteLeafs(Node *node) {
        if (!node) {
            return nullptr;
        }
        if (!node->m_pLeft && !node->m_pRight) {
            return nullptr;
        }
        node->m_pLeft = deleteLeafs(node->m_pLeft);
        node->m_pRight = deleteLeafs(node->m_pRight);
        return node;
    }
    
    int recCount() {
        return recCount(m_pRoot);
    }
    
    int recCount(Node *node) {
        return !node ? 0 : recCount(node->m_pLeft) + recCount(node->m_pRight) + 1;
    }
    
    bool insert(int iKey, const string& crData) {
        return insertRec(m_pRoot, iKey, crData);
    }

    static bool insertRec(Node*& rpNode, int iKey, const string& crData) {
        if (!rpNode) {
            rpNode = new Node(iKey, crData);
            return true;
        }
        if (iKey < rpNode->m_iKey) {
            return insertRec(rpNode->m_pLeft, iKey, crData);
        }
        if (iKey > rpNode->m_iKey) {
            return insertRec(rpNode->m_pRight, iKey, crData);
        }
        else {
            return false;
        }
    }

   friend ostream& operator << (ostream& os, BinTree& bt) {
        if (bt.m_pRoot) {
            bt.printTree(os, bt.m_pRoot);
        }
        return os;
    }
    
    int secondLeast() {
        return secondLeast(m_pRoot);
    }
    
    int secondLeast(Node *node) {
        Node *parent = nullptr;
        Node *child = node;
        while (child->m_pLeft) {
            parent = child;
            child = child->m_pLeft;
        }
        if (!child->m_pRight) {
            return parent->m_iKey;
        }
        child = child->m_pRight;
        while (child->m_pLeft) {
            child = child->m_pLeft;
        }
        return child->m_iKey;
    }
   
    void printTree(ostream& os, Node *node) {
        if (!node) {
            return;
        }
        cout << node->m_data << ": ";
        if (node->m_pLeft) {
            cout << "Left: " << node->m_pLeft->m_data <<"; ";
        }
        if (node->m_pRight) {
            cout << "Right: " << node->m_pRight->m_data <<"; ";
        }
        cout << endl;
        printTree(os, node->m_pLeft);
        printTree(os, node->m_pRight);
    }
    
    
    bool remove(int iKey) {
        Node **tmp = &m_pRoot;
        while ((&tmp) != nullptr) {
            if (iKey < (*tmp)->m_iKey) {
                tmp = &((*tmp)->m_pLeft);
            }
            else if (iKey > (*tmp)->m_iKey) {
                tmp = &((*tmp)->m_pRight);
            }
            else {
                Node *pToDelete = nullptr;
                if ((*tmp)->m_pRight == nullptr) {
                    pToDelete = *tmp;
                    *tmp = (*tmp)->m_pLeft;
                }
                else {
                    Node **pNF = &((*tmp)->m_pRight);
                    while ((*pNF)->m_pLeft != nullptr) {
                        pNF = &(*pNF)->m_pLeft;
                    }
                    pToDelete = *pNF;
                    (*tmp)->m_iKey = (*pNF)->m_iKey;
                    (*tmp)->m_data = (*pNF)->m_data;
                    *pNF = (*pNF)->m_pRight;
                }
                delete pToDelete;
                return true;
            }
        }
        return false;
    }
};
