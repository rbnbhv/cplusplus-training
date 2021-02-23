#include <iostream>
using namespace std;

class BinTree {
    struct Node {
        int m_key;
        string m_data;
        Node *m_pLeft = nullptr;
        Node *m_pRight = nullptr;
        
        Node(int key, const string& crData) : m_key(key), m_data(crData){
        }
    };
    
private:
    Node* m_pRoot = nullptr;
    
public:
    BinTree() {
    }
    
    BinTree(const BinTree& bt) {
        m_pRoot = copyHelper(bt.m_pRoot);
    }
    
    ~BinTree() {
        destroyRec(m_pRoot);
    }
    
    Node* copyHelper(Node *node) {
        if (!node) {
            return nullptr;
        }
        Node *copyTree = new Node(node->m_key, node->m_data);
        copyTree->m_pLeft = copyHelper(node->m_pLeft);
        copyTree->m_pRight = copyHelper(node->m_pRight);
        return copyTree;
    }
    
    void destroyRec(Node *node) {
        if (node) {
            destroyRec(node->m_pLeft);
            destroyRec(node->m_pRight);
            delete node;
        }
    }
    
    string* iterSearch(int key) {
        Node *p_tmp = m_pRoot;
        while (p_tmp) {
            if (p_tmp->m_key == key) {
                return &p_tmp->m_data;
            }
            p_tmp = key < p_tmp->m_key ? p_tmp->m_pLeft : p_tmp->m_pRight;
        }
        return nullptr;
    }
    
    string* recSearch(int key) {
        return recSearch(m_pRoot, key);
    }
    
    string* recSearch(Node *p_tmp, int key) {
        if (!p_tmp) {
            return nullptr;
        }
        if (p_tmp->m_key == ey) {
            return &p_tmp->m_data;
        }
        if (key < p_tmp->m_key) {
            return recSearch(p_tmp->m_pLeft, key);
        }
        else {
            return recSearch(p_tmp->m_pRightm key);
        }
    }
    
    void deleteLeafs() {
        m_pRoot = deleteLeafs(m_pRoot);
    }
    
    Node *deleteLeafs(Node *node) {
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
    
    bool insertRec(int key, const string& crData) {
        return insertRec(m_pRoot, key, crData);
    }
    
    static bool insertRec(Node *&rpNode, int key, const string& crData) {
        if (!rpNode) {
            rpNode = new Node(key, crData);
            return true;
        }
        else {
            while (rpNode) {
                if (key < rpNode->m_key) {
                    insertRec(rpNode->m_pLeft, key, crData);
                }
                else if (key > rpNode->m_key) {
                    insertRec(rpNode->m_pRight, key, crData);
                }
                else {
                    return false;
                }
            }
        }
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
            return parent->m_key;
        }
        child = child->m_pRight;
        while (child->m_pLeft) {
            child = child->m_pLeft;
        }
        return child->m_key;
    }
    
    friend ostream& operator <<(ostream& os, BinTree& bt) {
        if (bt.m_pRoot) {
            bt.printTree(os, bt.m_pRoot);
        }
        return os;
    }
    
    void deleteSingle() {
        m_pRoot = deleteSingle(m_pRoot);
    }
    
    Node* deleteSingle(Node *node) {
        if (!node) {
            return nullptr;
        }
        node->m_pLeft = deleteSingle(node->m_pLeft);
        node->m_pRight = deleteSingle(node->m_pRight);
        if (!node->m_pLeft && node->m_pRight || node->m_pLeft && !node->m_pRight) {
            Node *child = node->m_pLeft ? node->m_pLeft : node->m_pRight;
            delete node;
            return child;
        }
        return node;
    }
};
