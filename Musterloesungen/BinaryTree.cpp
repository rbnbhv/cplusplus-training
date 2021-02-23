#include <iostream>
using namespace std;

class BinTree {
    struct Node {
        int m_key;
        string m_data;
        Node *m_pLeft = nullptr;
        Node *m_pRight = nullptr;
        
        Node(int key, const string& data) : m_key(key), m_data(data) {
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
    
    BinTree& operator =(const BinTree& bt) {
        if (this == &bt) {
            return *this;
        }
        destroyRec(m_pRoot);
        m_pRoot = copyHelper(bt.m_pRoot);
        return *this;
    }
    
    void destroyRec(Node *node) {
        if (node) {
            destroyRec(node->m_pLeft);
            destroyRec(node->m_pRight);
            delete node;
        }
    }
    
    Node* copyHelper(Node *node) {
        if (!node) {
            return nullptr;
        }
        Node *copyRoot = new Node(node->m_key, node->m_data);
        copyRoot->m_pLeft = copyHelper(node->m_pLeft);
        copyRoot->m_pRight = copyHelper(node->m_pRight);
        return copyRoot;
    }
    
    // Iterative Suche
    string* iterSearch(int key) {
        Node *p_Tmp = m_pRoot;
        while (p_Tmp) {
            if (key == p_Tmp->m_key) {
                return &p_Tmp->m_data;
            }
            p_Tmp = (key < p_Tmp->m_key) ? p_Tmp->m_pLeft : p_Tmp->m_pRight;
        }
        return nullptr;
    }
    
    // Rekursive Suche
    string *recSearch(int key) {
        return recSearch(m_pRoot, key);
    }
    
    string *recSearch(Node *p_Tmp, int key) {
        if(!p_Tmp) {
            return nullptr;
        }
        if(key == p_Tmp->m_key) {
            return &p_Tmp->m_data;
        }
        if (key < p_Tmp->m_key) {
            return recSearch(p_Tmp->m_pLeft, key);
        }
        else {
            return recSearch(p_Tmp->m_pRight, key);
        }
    }
    
    int recCount() {
        return recCount(m_pRoot);
    }
    
    int recCount(Node* node) {
        return !node ? 0 : recCount(node->m_pLeft) + recCount(node->m_pRight) + 1;
    }
    
    bool insert2(int iKey, const string& crData) {
        return insertRec2(m_pRoot,iKey,crData);
    }
    
    static bool insertRec2(Node*& rpNode, int key, const string& crData) {
        if (!rpNode) {
            rpNode = new Node(key,crData);
            return true;
        } else {
            if (key < rpNode->m_key)
                return insertRec2(rpNode->m_pLeft,key,crData);
            else if (rpNode->m_key < key)
                return insertRec2(rpNode->m_pRight,key,crData);
            else
                return false;
        }
    }
    
    void printTree(ostream& os, Node* node) {
        if(!node)
            return;
        cout << node->m_data << ":  ";
        if(node->m_pLeft)
            cout << "Left: " << node->m_pLeft->m_data << "; ";
        if(node->m_pRight)
            cout << "Right: " << node->m_pRight->m_data << "; ";
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
