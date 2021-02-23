class BinTree {
    struct Node {
        
    };
    
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
        Node *copyRoot = new Node(node->m_iKey, node->m_Data);
        copyRoot->m_pLeft = copyTree(node->m_pLeft);
        copyRoot->m_pRight = copyTree(node->m_pRight);
        return copyRoot;
    }
    
    string* iterSearch(int iKey) {
        Node *p_Tmp = m_pRoot;
        while (p_Tmp) {
            if (iKey == p_Tmp->m_iKey) {
                return &p_Tmp->m_data;
            }
            p_Tmp = (iKey < p_Tmp->m_iKey) ? p_Tmp->m_pLeft : p_Tmp->m_pRight;
        }
        return nullptr;
    }
    
    string* recSearch(int iKey) {
        return recSearch(m_pRoot, iKey);
    }
    
    string* recSearch(Node *p_Tmp, int iKey) {
        if (!p_Tmp) {
            return nullptr;
        }
        else if(iKey == p_Tmp->m_iKey) {
            return &p_Tmp->m_data;
        }
        else if(iKey < p_Tmp->m_iKey) {
            return recSearch(p_Tmp->m_pLeft, iKey);
        }
        else {
            return recSearch(p_Tmp->m_pRight, iKey);

        }
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
    
    static bool insertRec(Node &*rpNode, int iKey, const string& crData) {
        if (!rpNode) {
            rpNode = new Node(iKey, crData);
            return true;
        }
        else {
            if (iKey < rpNode->m_iKey) {
                insertRec(rpNode->m_pLeft, iKey, crData);
            }
            else if(iKey > rpNode->m_iKey) {
                insertRec(rpNode->m_pRight, iKey, crData);
            }
            else {
                return false;
            }
        }
    }
    
    bool insert(int iKey, const string& crData) {
        return insertRec(m_pRoot, iKey, crData);
    }
    
    static bool insertRec(Node &*rpNode, int iKey, const string &crData) {
        if (!rpNode) {
            rpNode = new Node(iKey, crData);
            return true;
        }
        else {
            if (iKey < rpNode->m_iKey) {
                insertRec(rpNode->m_pLeft, iKey, crData);
            }
            else if(iKey > rpNode->m_iKey) {
                insertRec(rpNode->m_pRight, iKey, crData);
            }
            else {
                return false;
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
            return parent->m_iKey;
        }
        child = child->m_pRight;
        while (child->m_pLeft) {
            child = child->m_pLeft;
        }
        return child->m_iKey;
    }
    
    void printTree(ostream& os, BinTree& bt) {
        if (!node) {
            return;
        }
        cout << node->m_data << ": ";
        if (node->m_pLeft) {
            cout << "Left: " << node->m_pLeft->m_data << "! ";
        }
        if (node->m_pRight) {
            cout << "Right: " << node->m_pRight->m_data << "! ";
        }
        cout << endl;
        printTree(os, node->m_pLeft);
        printTree(os, node->m_pRight);
    }
    
    ostream& operator << (ostream& os, BinTree& bt) {
        if (bt.m_pRoot) {
            bt.printTree(os, bt.m_pRoot);
        }
        return os;
    }
};
