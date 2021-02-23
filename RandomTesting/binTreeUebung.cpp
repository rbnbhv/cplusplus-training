#include <iostream>
using namespace std;

class BinTree {
    struct Node {
        int m_iKey;
        string m_data;
        Node *m_pLeft = nullptr;
        Node *m_pRight = nullptr;
        
        Node(int key, const string& crData) : m_iKey(key), m_data(crData) {
        }
    };
private:
    Node *m_pRoot = nullptr;
    
public:
    BinTree() {
    }
    
    BinTree(const BinTree &bt) {
        m_pRoot = copyTree(bt.m_pRoot);
    }
    
    ~BinTree() {
        destroyRec(m_pRoot);
    }
    
    BinTree& operator =(const BinTree& bt) {
        if (this == &bt) {
            return *this;
        }
        destroyRec(m_pRoot);
        m_pRoot = copyTree(bt.m_pRoot);
        return *this;
    }
    
    void destroyRec(Node *node) {
        if (node) {
            destroyRec(node->m_pLeft);
            destroyRec(node->m_pRight);
            delete node;
        }
    }
    
    Node* copyTree(Node *node) {
        if (!node) {
            return nullptr;
        }
        Node *copyRoot = new Node(node->m_iKey, node->m_data);
        copyRoot->m_pLeft = copyTree(node->m_pLeft);
        copyRoot->m_pRight = copyTree(node->m_pRight);
        return copyRoot;
    }
};
